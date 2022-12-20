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
int day5(void)
{

    ifstream File("input_5");
    string line;
    vector<string> inputs;
    vector<string> moves;
    int length;
    // Read stack initial
    while (std::getline(File, line))
    {
        cout << line << endl;
        // https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        // https://stackoverflow.com/questions/4072363/how-to-extract-digits-from-the-end-of-string
        if (line.find("1") != std::string::npos)
        {
            length = stoi(line.substr(line.size() - 1));
            break;
        }
        inputs.push_back(string(line));
    }

    cout << length << endl;

    vector<deque<char>> stack;
    deque<char> q;
    stack.push_back(q);
    for (int i = 0; i < length; i++)
    {
        deque<char> q;
        stack.push_back(q);
    }
    // Push stack to storage
    for (int i = inputs.size() - 1; i >= 0; i--)
    {

        string row = inputs[i];
        cout << row << "\n";

        for (int k = 1; k < row.length(); k += 4)
        {
            if (!isspace(row[k]))
            {
                int index = (k - 1) / 4 + 1;
                stack[index].push_back(row[k]);

                cout << row[k] << ", " << index << "\n";
            }
        }
    }
    cout << "\n";
    std::getline(File, line);

    // Move through stack
    while (std::getline(File, line))
    {
        cout << line << endl;

        std::regex regex_pairs("\\ ");
        vector<string> move_order;
        splitstring(line, regex_pairs, move_order);

        int move = stoi(move_order[1]);
        int from = stoi(move_order[3]);
        int to = stoi(move_order[5]);
        cout << "move: " << move << " from: " << from << " to: " << to << "\n";
        char temp;
        deque<char> temp_q;
        // part 1
        /*
        for (int i = 0; i < move; i++){
            temp = stack[from].back();
            stack[from].pop_back();
            stack[to].push_back(temp);

        }
        */
        // Part 2
        if (move == 1)
        {
            temp = stack[from].back();
            stack[from].pop_back();
            stack[to].push_back(temp);
        }else{
            for (int i = 0; i < move; i++)
            {

                temp_q.push_front(stack[from].back());
                stack[from].pop_back();
            }
            for (int i = 0; i < move; i++)
            {
                stack[to].push_back(temp_q.front());
                temp_q.pop_front();
            }

        }
    }

    cout << "\n";

    for (int i = 0; i <= length; i++)
    {
        cout << i << ":";

        while (!stack[i].empty())
        {
            cout << stack[i].front();
            stack[i].pop_front();
        }
        cout << "\n";
    }
}