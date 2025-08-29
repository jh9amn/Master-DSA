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

/*
[
    [ 0,0  0,1  0,2  0,3 ],
    [ 1,0  1,1  1,2  1,3 ],
    [ 2,0  2,1  2,2  2,3 ],
    [ 3,0  3,1  3,2  3,3 ],
]

Their difference (i-j) have unique value, store them into map at their diagonal difference
*/


// using map 
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> mp;

        // traverse on every ele and store them to their diagonal diffrence
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int diagonalDiff = i-j;
                mp[diagonalDiff].push_back(grid[i][j]);
            }
        }

        for(auto &it: mp) {
            // do opposite sorting to access ele in O(1)
            if(it.first >= 0) {
                sort(begin(it.second), end(it.second));
            }
            else{
                sort(begin(it.second), end(it.second), greater<int> ());
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // access ele at O(1)
                int diagonalDiff = i-j;
                grid[i][j] = mp[diagonalDiff].back();
                mp[diagonalDiff].pop_back();
            }
        }

        return grid;
    }
};
