#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl",
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv",
        mp[9] = "wxyz";

        string path;
        function<void(int)> backtrack = [&](int i) -> void {
            if(i == digits.size()) {
                ans.push_back(path);
                return;
            }

            string s = mp[digits[i] - '0'];
            // backtrack
            for(char c : s){
                path += c;
                backtrack(i+1);
                path.pop_back();
            }
            return;
        };
        
        backtrack(0);
        return ans;
    }
};