#include<bits/stdc++.h>
using namespace std;
int main() {
}


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        function<void(int, int, bool)> sortDiagonal = [&] (int row, int col, bool asc) {
            int i=row;
            int j=col;

            vector<int> temp;
            while(i<n && j<m){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }

            // nlogn
            if(asc) sort(begin(temp), end(temp));
            else sort(begin(temp), end(temp), greater<int>());

            for(auto it : temp) {
                grid[row++][col++] = it;
            }
        };

        // n * nlogn
        // decending order
        for(int i=0; i<n; i++){
            sortDiagonal(i, 0, false);
        }

        // ascending order
        for(int j=1; j<m; j++){
            sortDiagonal(0, j, true);
        }

        return grid;

    }
};
