#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;
        bool flag = true;
        for(int j=0; j<m; j++) {
            int row = 0;
            int col = j;

            vector<int> temp;
            while(col != -1 && row < n && !flag) {
                ans.push_back(mat[row++][col--]);
            }

            while(col != -1 && row < n && flag) {
                temp.push_back(mat[row++][col--]);
            }

            if(flag) {
                reverse(begin(temp), end(temp));
                for(auto it : temp) {
                    ans.push_back(it);
                }
            }
            flag = !flag;
        }

        for(int i=1; i<n; i++ ){
            int row = i;
            int col = m-1;

            vector<int> temp;
            while(row < n && col >= 0 && !flag){
                ans.push_back(mat[row++][col--]);
            }

            while(row < n && col >= 0 && flag){
                temp.push_back(mat[row++][col--]);
            }

            if(flag) {
                reverse(begin(temp), end(temp));
                for(auto it : temp) {
                    ans.push_back(it);
                }
            }

            flag = !flag;
        }

        return ans;
    }
};