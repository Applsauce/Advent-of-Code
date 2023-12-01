#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#include <sstream>
#include <regex>
using namespace std;

class Node
{
public:
    int data;
    bool dir;
    string name;
    Node *parent;
    vector<Node *> children;

    // Default constructor
    Node()
    {
        data = 0;
        parent = NULL;
        dir = true;
        name = "";
    }

    bool operator==(const Node &rhs) const
    {

        // cout << data << "|" << rhs.data << "," << name << "|" << rhs.name;
        return ((data == rhs.data) && (name == rhs.name));
    }
};
// https://nolowiz.com/split-strings-in-cpp/
void splitstring(string &str,
                 regex re,
                 vector<string> &tokens)
{
    string word; // to store the token (splitted string)
    regex_token_iterator<string::iterator> it(str.begin(), str.end(), re, -1);
    regex_token_iterator<string::iterator> rend;

    while (it != rend)
    {
        word = *it++;
        if (word != str)
            tokens.push_back(word);
    }
}
Node *findNode(Node *n, vector<Node *> vec)
{
    for (Node *n2 : vec)
    {

        if (*n2 == *n)
        {
            return n2;
        }
    }

    return NULL;
}

void countDirs(Node *n)
{

    for (Node *child : n->children)
    {
        n->data += child->data;
        countDirs(n);
    }
}
void deleteDirs(Node *n, int tab, vector<Node *> &largest, int deleteThis)
{
    if ((n->data <= deleteThis) && (n->dir == true))
    {
        largest.push_back(n);
    }
    string stringTab;
    for (int i = 0; i < tab; i++)
    {
        stringTab += "\t";
    }
    cout << stringTab << "-" << n->name << " " << n->data << ":\n";
    for (Node *child : n->children)
    {
        deleteDirs(child, tab + 1, largest, deleteThis);
    }
}

void printDirs(Node *n, int tab, vector<int> &largest)
{
    if ((n->data <= 100000) && (n->dir == true))
    {
        largest.push_back(n->data);
    }
    string stringTab;
    for (int i = 0; i < tab; i++)
    {
        stringTab += "\t";
    }
    cout << stringTab << "-" << n->name << " " << n->data << ":\n";
    for (Node *child : n->children)
    {
        printDirs(child, tab + 1, largest);
    }
}
int main(void)
{

    ifstream File("input_7");
    string line;
    vector<string> inputs;
    std::regex regex_space("\\ ");
    std::getline(File, line);
    vector<string> cmd;
    splitstring(line, regex_space, cmd);
    Node *root = new Node;
    cout << line << endl;
    root->name = cmd[2];
    Node *currNode = root;
    Node *it;
    Node *tNode = new Node;
    tNode->name = root->name;
    tNode->data = root->data;
    bool test = (*root == *tNode);
    cout << test;

    // Read stack initial
    while (std::getline(File, line))
    {
        inputs.push_back(line);
    }
    for (int i = 0; i < inputs.size(); i++)
    {
        line = inputs[i];
        cout << "\t" << i << ": " << line << endl;
        vector<string> cmd;
        splitstring(line, regex_space, cmd);
        if (cmd[0] == "$")
        {

            if (cmd[1] == "cd")
            {
                cout << "Curr node. name: " << currNode->name << endl;

                if (cmd[2] == "..")
                { // move up
                    currNode = currNode->parent;
                    cout << "parent node. name: " << currNode->name << " data:" << currNode->data << endl;
                }
                else
                {
                    Node *child = new Node;
                    child->parent = currNode;
                    child->name = cmd[2];
                    child->dir = true;

                    // https://www.techiedelight.com/check-vector-contains-given-element-cpp/
                    it = findNode(child, currNode->children);
                    if (it == NULL)
                    {
                        currNode->children.push_back(child);
                        currNode = child;
                        cout << "New node. name: " << child->name << " data:" << child->data << endl;
                        // std::cout << "Element not found";
                    }
                    else
                    { // already a known child

                        cout << "Iterator node. name: " << child->name << " data:" << child->data << endl;
                        currNode = it;
                        delete child;
                        child = NULL;
                    }
                }
            }
            else if (cmd[1] == "ls")
            {

                // Check lines until next command
                for (int k = i + 1; (k < inputs.size()); k++)
                {
                    cout << "\t\t"
                         << "k: " << k << " line: " << inputs[k] << endl;

                    if ((inputs[k][0] != '$'))
                    {
                        vector<string> ls;
                        splitstring(inputs[k], regex_space, ls);

                        Node *child = new Node;
                        child->parent = currNode;
                        child->name = ls[1];
                        child->dir = true;
                        cout << "New node. name: " << child->name << endl;

                        // https://www.techiedelight.com/check-vector-contains-given-element-cpp/
                        it = findNode(child, currNode->children);
                        if (it == NULL)
                        {
                            if (ls[0] != "dir")
                            {
                                child->data = stoi(ls[0]);
                                child->dir = false;
                                // update all parents
                                Node *temp = new Node;
                                temp->parent = child->parent;

                                while (temp->parent != NULL)
                                {
                                    temp = temp->parent;
                                    temp->data += child->data;
                                }
                            }
                            currNode->children.push_back(child);

                            cout << "ls node. name: " << child->name << " data:" << child->data << endl;
                            // std::cout << "Element not found";
                        }
                        else
                        {
                            cout << "Existing node. name: " << child->name << " data:" << child->data << endl;

                            delete child;
                            child = NULL;
                        }
                    }
                    else
                    {

                        k = inputs.size(); // break out
                    }
                }
            }
        }
    }

    while (currNode->parent != NULL)
    {
        currNode = currNode->parent;
    }
    // update sizes
    // countDirs(currNode);

    // print final list
    // vector<int> largest;
    // printDirs(currNode, 0, largest);

    cout << endl;
    int sum = 0;

    int maxSize = 70000000;
    int left = maxSize - currNode->data;
    int update = 30000000;
    int deleteThis = update - left;
    vector<Node *> largest;
    deleteDirs(currNode, 0, largest, maxSize);
    Node *smallest = new Node;
    smallest->data = currNode->data;
    for (Node *n : largest)
    {
        if ((n->data < smallest->data) && (n->data >= deleteThis))
        {
            smallest = n;
        }
    }
    cout << "name:" <<smallest->name << "\tdata:" << smallest->data << "\tdir:" << smallest->dir << endl;
    // part 1
    // for ( Node i: largest){
    //    cout << "sum: " << sum+ i << ", i: " << i << endl;
    //   sum += i;
    //}
}