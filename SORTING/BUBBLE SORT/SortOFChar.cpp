/*
sort a string in decreasing order of values accociatted after removal of values smaller than X...
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "ABXZXYSYEZI";
    string str ;

    // 
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]>='X')
        {
            str.push_back(s[i]);
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        bool flag = true;
        for (int j = 0; j < str.length()-1-i; j++)
        {
            if (str[j] > str[j + 1])
            {
                swap(str[j], str[j + 1]);
            }
        }
        if(flag == true)
        break;
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i] << " ";
    }

    return 0;
}
