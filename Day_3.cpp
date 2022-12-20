#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int charToPriority(char c)
{
    int prio = int(c);
    prio -= 96;
    if(std::isupper(c)){
    // A = 65, a = 97, Z = 90, z = 122
        prio = prio + 22 + 10 + 26;

    }
    return prio;
}

int day3(void){

    std::ifstream File ("input_3");
    std::string line;
    int score = 0;
    while (std::getline(File, line))
    {
        //string part1 = line.substr(0, line.length() / 2);
        //string part2 = line.substr(line.length() / 2, line.length() / 2);

        string group1 = line;
        getline(File, line);
        string group2 = line;

        getline(File, line);
        string group3 = line;

        char duplicate;
        for (int i = 0; i < group1.length() ; i++){
            for (int k = 0; k < group2.length() ; k++){
                for (int j = 0; j < group3.length() ; j++){
                    if ((group1[i] == group2[k]) && (group2[k] == group3[j])){
                        duplicate = group1[i];
                    }
                }
            }
        }
        cout << duplicate << endl;
        int prio = charToPriority(duplicate);
        cout << prio << endl;
        score += prio;
        std::cout <<score  - prio<< " + " << prio << "= "<< score<<  std::endl;

    }

}
