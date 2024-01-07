#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            int curr = 0;
            for(int j=0; j < bank[i].size(); j++){
                if(bank[i][j] == '1')  curr++;
            }
            ans += curr * prev;
            if(curr > 0)    prev = curr;
        }
        return ans;
    }
};

int main(){

}