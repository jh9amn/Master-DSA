#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> str(numRows,"");
        int n = s.size();
        int i = 0;
        while(i < n){
            // fil up every no of numRows string start char of s[i++]
            for(int idx = 0; idx < numRows && i < n; idx++){
                str[idx] += s[i++];
            }
            // then start fill second last string with char of s[i++] till numRows - 2 times
            for(int idx = numRows-2; idx > 0 && i < n; idx--){
                str[idx] += s[i++];
            }

            // and repeat this so on till i != n... 
        }

        string ans = "";
        for(auto &ss : str){
            ans += ss;
        }

        return ans;
    }
};