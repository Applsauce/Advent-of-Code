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
bool edge(int x, int y, int sizeX, int sizeY)
{
    return (x == 0 || y == 0 || x == sizeX - 1 || y == sizeY - 1);
}
bool inBounds(int x, int y, int sizeX, int sizeY)
{
    return (x >= 0 && y >= 0 && x < sizeX && y < sizeY);
}
// bool visible(int x, int y, vector<vector<int>>  )

int main(void)
{

    ifstream File("test_8");
    string line;
    vector<string> inputs;
    int sizeX = 0;
    int sizeY = 0;
    // Read stack initial
    while (std::getline(File, line))
    {
        inputs.push_back(line);
        cout << line << endl;
        sizeY++;
    }
    sizeX = inputs[0].size();
    cout << "sizeX:" << sizeX << " sizeY:" << sizeY << endl
         << endl;
    // https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
    vector<vector<int>> matrix(sizeX, vector<int>(sizeY));
    for (int i = 0; i < sizeX; i++)
    {
        // cout << endl;
        for (int k = 0; k < sizeY; k++)
        {
            matrix[i][k] = inputs[i][k] - '0';
            // cout << matrix[i][k];
            // cout << ", i: " << i << ", k: " << k << endl;
        }
    }
    vector<vector<bool>> visible(sizeX, vector<bool>(sizeY));
    for (int x = 0; x < sizeX; x++)
    {
        cout << endl;
        for (int y = 0; y < sizeY; y++)
        {
            // if ((x == 0 && y == 0) || (x == 0 && y == sizeY - 1) || (x == sizeX - 1 && y == 0) || (x == sizeX - 1 && y == sizeY - 1))
            if ((x == 0) || (y == sizeY - 1) || (y == 0) || (x == sizeX - 1))

            {
                visible[x][y] = true;
            }
            cout << visible[x][y];
        }
    }
    cout << endl
         << endl;
    int it = 1;
    int oldVisible = -1;
    int newVisible = 0;
    while (newVisible != oldVisible)
    {
        cout << "Iteration " << it++ << endl;
        oldVisible = newVisible;
        for (int x = 0; x < sizeX; x++)
        {
            for (int y = 0; y < sizeY; y++)
            {
                if (!visible[x][y])
                {
                    for (int xx = -1; xx <= 1; xx++)
                    {
                        for (int yy = -1; yy <= 1; yy++)
                        {
                            if ((xx == yy) || (xx + yy == 0))
                            {
                                continue;
                            }
                            else
                            {
                                int oX = x;
                                int oY = y;
                                int nX = oX + xx;
                                int nY = oY + yy;
                                bool validCoord = inBounds(nX, nY, sizeX, sizeY) && ((matrix[nX][nY] < matrix[x][y]));
                                while (validCoord) // get a direction and keep moving
                                {
                                    // validCoord = inBounds(nX, nY, sizeX, sizeY) && visible[nX][nY] && (matrix[nX][nY] < matrix[x][y]);
                                    if (edge(nX, nY, sizeX, sizeY)) // then we have a valid visible
                                    {

                                        visible[x][y] = true;
                                        newVisible++;
                                        validCoord = false;
                                    }
                                    else
                                    {
                                        // Keep stepping
                                        oX = nX;
                                        oY = nY;
                                        nX = oX + xx;
                                        nY = oY + yy;
                                        validCoord = inBounds(nX, nY, sizeX, sizeY) && ((matrix[nX][nY] < matrix[x][y]));
                                    }
                                }
                            }
                        }
                    }
                }
                cout << visible[x][y];
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Final Print" << endl;
    int vis = 0;
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            vis += visible[x][y];
            cout << visible[x][y];
        }
        cout << endl;
    }
    cout << endl
         << "Sum visible:" << vis << endl;

    // part 2
    int maxMult = 1;
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            if (true)
            {
                // cout << matrix[x][y];
                int mult = 1;
                for (int xx = -1; xx <= 1; xx++)
                {
                    for (int yy = -1; yy <= 1; yy++)
                    {
                        if ((xx == yy) || (xx + yy == 0))
                        {
                            continue;
                        }

                        else
                        {
                            if ( matrix[x][y] == 5){
                                int b = 0;
                            }
                            int vis = 1;
                            int nX = x + xx;
                            int nY = y + yy;
                            bool validCoord = inBounds(nX, nY, sizeX, sizeY) && ((matrix[nX][nY] < matrix[x][y]));
                            if (validCoord)
                            {
                                if (edge(nX, nY, sizeX, sizeY))
                                {
                                    mult = 0;
                                    validCoord = false;
                                }
                            }
                            while (validCoord) // get a direction and keep moving
                            {

                                // validCoord = inBounds(nX, nY, sizeX, sizeY) && visible[nX][nY] && (matrix[nX][nY] < matrix[x][y]);
                                if ((edge(nX, nY, sizeX, sizeY))) // then we have a valid visible
                                {
                                    validCoord = false;
                                }
                                else
                                {
                                    // Keep stepping
                                    nX += xx;
                                    nY += yy;
                                    validCoord = inBounds(nX, nY, sizeX, sizeY);
                                }
                                if ((matrix[nX][nY] < matrix[x][y]))
                                {
                                    vis++;
                                }
                            }

                            mult *= vis;
                            cout << endl
                                 << "val:" << matrix[x][y] << ", x:" << x << ", y:" << y << ", xx:" << xx << ", yy:" << yy;
                            cout << "\tmult:" << mult << ", vis:" << vis << endl;
                        }
                    }
                }
                if (mult > maxMult)
                {
                    maxMult = mult;
                }
            }
        }
    }
    cout << endl
         << maxMult << endl;
}