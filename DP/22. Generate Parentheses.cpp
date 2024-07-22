#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    void solve(vector<string> &ans, string s, int n, int left, int right){
        if(left == n and right == n){
            ans.push_back(s);
            return;
        }

        if(left < n) {
            solve(ans, s + '(' , n, left + 1, right);
        }
        if(right < left) {
            solve(ans, s + ')', n, left, right + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string > ans;
        string s = "";

        solve(ans, s, n, 0, 0);

        return ans;
        
    }
};