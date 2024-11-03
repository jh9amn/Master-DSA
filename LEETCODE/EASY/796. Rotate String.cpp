#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        string doubled = s + s;
        for(int i=0; i<doubled.size(); i++){
            string subString = doubled.substr(i, goal.length());
            if (goal == subString)
                return true;
        }
        return false;
    }
};

/**
 * Input: s = "abcde", goal = "abced"
 * s + s becomes "abcdeabcde".
 * "abced" is not a substring of "abcdeabcde", so the output is false.
 */