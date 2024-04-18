#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // here we can use dfs too but it is good when there are to many island but for single island it just increase          our t.c. ..
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dirx[] = {0,1,0,-1};
        int diry[] = {1,0,-1,0};
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int ni = dirx[k] + i;
                        int nj = diry[k] + j;
                        // outoff bound side bala edge...
                        if(ni == -1 || nj == -1 || ni == n || nj == m){
                            count++;
                        }
                        // aur jis side 0 means water side bala edge...
                        else if(grid[ni][nj] == 0){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};


int main(){


}