#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:

// T.C  = O(n)
// S.C = nothering used, just a variable(constant)..
    int minChanges(string s) {
        int count = 0;
        for(int i=0; i<s.size()-1; i+=2){
            if(s[i] != s[i+1]){
                count++;
            }
        }
        return count;
    }
};

/**
** THought Process to convert the string into a simple binary string where the left side all 0's or 1's.. 
                                                                                right side all 0's or 1's..
* example : 100100111001111111

first change need..
first i = 0;
if(s[0] != s[0+1]) count++
... 000100111001111111

second change need..
second i = 2;
if(s[2] != s[2+1]) count++
... 000000111001111111

third change need..
third i = 8;
if(s[8] != s[8+1]) count++
... 000000111101111111

fourth change need..
fourth i = 10;
if(s[10] != s[10+1]) count++
... 000000111111111111

i+=2 

*/