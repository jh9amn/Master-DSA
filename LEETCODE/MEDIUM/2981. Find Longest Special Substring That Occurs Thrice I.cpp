#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int cnt = 0;

        unordered_map<string, pair<int, int>> mp;

        for(int i=0; i<n; i++){
            string ss = "";
            for(int j=i; j<n; j++){
                if(ss.size() > 0 and ss[ss.size() - 1] != s[j]) break;
                ss += s[j];
                mp[ss].first++;
                mp[ss].second = ss.size();
            }
        }

        int maxiLen = INT_MIN;
        for(auto it : mp){
            if(it.second.first >= 3) {
                maxiLen = max(maxiLen, it.second.second);
            }
        }

        return maxiLen < 0 ? -1 : maxiLen;
    }
};