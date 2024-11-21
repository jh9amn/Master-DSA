#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    /* Steps...
    1> create grid with wall and gaurds
    2) mark cell until the distamce gourd can watch
    3) count the number of unguarded and unwalled cells
    **/

    bool isValid (int i, int j, int n, int m){
        return i >= 0 and i < m and j >= 0 and j < n;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int> (n,0));     // 0 = ungourded and unwalled

        // 1 = guard 
        // -1 = wall
        // 0 = no guard and no wall
        // 2 = mark as gaurdable

        for(auto it : walls){
            grid[it[0]][it[1]] = -1;
        }
        for(auto it : guards){
            grid[it[0]][it[1]] = 1;
        }


        // TLE
        // vector<vector<int>> dir = { {1,0}, {-1,0}, {0,-1}, {0, 1}};

        // for(auto guard : guards){
        //     int ni = guard[0];
        //     int nj = guard[1];
        //     for(auto dd : dir){
        //         ni += dd[0];
        //         nj += dd[1];
        //         while(isValid(ni, nj, n, m) and grid[ni][nj] != -1) {
        //             if(grid[ni][nj] == 0) grid[ni][nj] = 1;
        //             ni += dd[0];
        //             nj += dd[1];
        //         }

        //     }
        // }

        auto mark_gaurdable = [&] (int row, int col) {
            for(int i = row + 1; i<m; i++){
                if(grid[i][col] == -1 || grid[i][col] == 1) break;
                grid[i][col] = 2;
            }

            for(int i = row - 1; i>=0; i--){
                if(grid[i][col] == -1 || grid[i][col] == 1) break;
                grid[i][col] = 2;
            }

            for(int j = col + 1; j<n; j++){
                if(grid[row][j] == -1 || grid[row][j] == 1) break;
                grid[row][j] = 2;
            }

            for(int j = col - 1; j>=0; j--){
                if(grid[row][j] == -1 || grid[row][j] == 1) break;
                grid[row][j] = 2;
            }

        };


        // mark gaurd watch
        for (const auto& guard : guards) {
            mark_gaurdable(guard[0], guard[1]);
        }


        int countUnGuarded = 0; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) countUnGuarded++;
            }
        }
        return countUnGuarded;
    }
};