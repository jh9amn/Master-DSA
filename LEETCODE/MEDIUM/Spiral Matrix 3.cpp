#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows * cols;
        int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};    // direction for move right, down, left, up ...
        vector<vector<int>> ans(n, vector<int> (2,0));
        ans[0][0] = rStart;
        ans[0][1] = cStart;
        int count = 1;
        int step = 1;       // step to move on that point right, down, left, up..
        int idx = 0;

        while(count < n){
            // every time move in two direction with same step and then increase the step
            for(int direction=0; direction<2; direction++){
                int dr = dir[idx % 4][0];
                int dc = dir[idx % 4][1];

                for(int i=0; i<step; i++){
                    rStart += dr;
                    cStart += dc;

                    if(rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols) {
                        ans[count][0] = rStart;
                        ans[count][1] = cStart;
                        count++;
                    }
                }
                idx++;
            }
            step++;
        }
        return ans;
    }
};