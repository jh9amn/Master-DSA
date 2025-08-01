#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vis(n*n+1, 0);

        for(auto it : grid){
            for(auto s : it) {
                vis[s]++;
            }
        }

        vector<int> ans;
        for(int i=1; i<vis.size(); i++){
            if(vis[i] == 1) continue;
            else if(vis[i] == 2) ans.push_back(i);
        }
        for(int i=1; i<vis.size(); i++){
            if(vis[i] == 1) continue;
            else if(vis[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};