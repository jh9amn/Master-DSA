#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVal(vector<vector<int>>& grid, int n, int m){
        int maxi = INT_MIN;
        for(int i=n; i<=n+2; i++){
            for(int j=m; j<=m+2; j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2,0));
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                ans[i][j] = maxVal(grid, i, j);
            }
        } 
        return ans;
    }
};

int main(){

}