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
int main(void)
{

    ifstream File("input_6");
    string line;
    int nbrChars = 0;
    // int charLimit = 3; // part 1
    int charLimit = 13; // part 2

    string buffer;
    bool uniq;
    // Read stack initial
    while (std::getline(File, line))
    {
        nbrChars = 0;
        cout << endl;
        for (int i = 0; i < line.length(); i++)
        {
            buffer += line.substr(i, 1);
            nbrChars++;
            uniq = true;
            // cout << "i = " << i << ", nbrChars: " << nbrChars << endl;
            // cout << "line[i] = " << line.substr(i, 1) << ", buffer: " << buffer << endl;

            for (int k = 0; k < buffer.length() - 1; k++)
            {

                for (int p = k + 1; p < buffer.length(); p++)
                {
                    if (buffer[k] == buffer[p])
                    {
                        uniq = false;
                    }
                }
            }
            if (buffer.length() > charLimit)
            {
                // cout << buffer << endl;
                // cout << buffer.substr(1) << endl;
                buffer = buffer.substr(1);
            }
            if ((nbrChars > charLimit) && (uniq))
            {
                cout << nbrChars << endl;
                break;
            }
        }
    }
}