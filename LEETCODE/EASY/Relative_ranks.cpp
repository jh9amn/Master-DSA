#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> vp;
        for(int i=0; i<score.size(); i++){
            vp.push_back({score[i],i});
        }
        
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        
        int n = score.size();
        vector<string> ans(n);
        
        for(int i=0; i<n; i++){
            int idx = vp[i].second;
            int val = vp[i].first;
            
            if (i == 0) ans[idx] = "Gold Medal";
            else if(i == 1) ans[idx] = "Silver Medal";
            else if(i == 2) ans[idx] = "Bronze Medal";
            
            else ans[idx] = to_string(i+1);
        }
        return ans;
    }
};


int main(){

}