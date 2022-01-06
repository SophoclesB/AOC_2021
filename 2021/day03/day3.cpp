#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>

using std::string;
using std::vector;

const string dayThreeInput = "day3.txt";

vector<string> fileInput(string input)
{
    // converting the textfile to a vector of strings
    string temp;
    vector<string> deptharray = {};
    std::ifstream input_file(input);

    while(getline(input_file,temp))
    {
        deptharray.push_back(temp);
    }
    input_file.close();
    return deptharray;
}

int toDecimal(string binary)
{
    int decimal = 0, i = 0, rem;
    long long n = std::stoll(binary);
    while(n!=0)
    {
        rem = n % 10;
        n /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }
    return decimal;
}

int part1(vector<string> input1)
{
    string gamma, epsilon;
    int bitlength = input1[0].length();
    for (int i = 0; i < bitlength; ++i)
    {
        int count0 = 0;
        int count1 = 0;
        for(int j = 0; j < input1.size(); ++j)
        {
            if(input1[j][i] == '0')
                ++count0;
            else
                ++count1;
        }
        if(count0 > count1)
        {
            gamma += '0';
            epsilon += '1';
        }
        else
        {
            gamma += '1';
            epsilon += '0';
        }
    }
    int dgamma = toDecimal(gamma);
    int depsilon = toDecimal(epsilon);
    return dgamma * depsilon;
}

int main()
{
    vector<string> stringFileInputDay3 = fileInput(dayThreeInput);
    int sol1 = part1(stringFileInputDay3);
    printf("%d\n", sol1);
    return 0;
}
