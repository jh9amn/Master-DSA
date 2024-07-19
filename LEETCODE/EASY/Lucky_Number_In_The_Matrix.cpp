#include<bits/stdc++.h>
using namespace std;
int main(){

}


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row[n];
        int col[m];

        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<m; j++){
                mini = min(mini, matrix[i][j]);
            }
            row[i] = mini;
        }

        for(int i=0; i<m; i++){
            int maxi = 0;
            for(int j=0; j<n; j++){
                maxi = max(matrix[j][i], maxi);
            }
            col[i] = maxi;
        }

        vector<int> ans;
        // check the matrix[i][j] is smaller in his row and greater in his col
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == row[i] and matrix[i][j] == col[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};