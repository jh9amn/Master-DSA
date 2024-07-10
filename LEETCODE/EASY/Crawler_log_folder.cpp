#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0 ;
        int maxi = 0;
        for(auto it : logs){
            if(it[0] != '.') count++;
            else if(it[0] == '.' and it[1] == '.' and count != 0 ) count--;
        }
        return count;
    }
};

int main(){}