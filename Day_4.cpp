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

int day4(void)
{

    ifstream File("input_4");
    string line;
    vector<string> inputs;
    while (std::getline(File, line))
    {
        inputs.push_back(string(line));
        cout << line << endl;
    }
    int containedPairs = 0;
    // https://stackoverflow.com/questions/10058606/splitting-a-string-by-a-character
    for (int i = 0; i < inputs.size(); i++)
    {
        std::regex regex_pairs("\\,");
        vector<string> pairs;
        splitstring(inputs[i], regex_pairs, pairs);
        for (const auto v : pairs)
        {
            cout << v << "\n";
        }
        std::regex regex_range("\\-");
        vector<string> range_1;
        splitstring(pairs[0], regex_range, range_1);

        vector<string> range_2;
        splitstring(pairs[1], regex_range, range_2);

        // check if they overlap
        int r_1 = stoi(range_1[0]);
        int r_2 = stoi(range_1[1]);
        int r_3 = stoi(range_2[0]);
        int r_4 = stoi(range_2[1]);

        // part 1
        // if ( ((r_1 <= r_3) && (r_2 >= r_4) )||((r_1 >= r_3) && (r_2 <= r_4) )){
        //    containedPairs++;
        // }

        // part 2
        for ( int k = r_1; k <= r_2; k++)
        {
            for (int p = r_3; p <= r_4 ; p++){
                if (k == p ){
                    containedPairs++;
                    p = INT_MAX -1;
                    k = INT_MAX -1;
                }

            }
        }
    }

    // all_of(a.begin(), a.end(), [](int a_elt) {
    //     find(b.begin(), b.end(), a_elt) != b.end();
    cout << containedPairs << endl;
}