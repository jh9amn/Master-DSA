#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    void fillStone(vector<vector<char>> &ans, int count, int i, int j){
        while(count--){
            ans[i][j] = '#';
            i--;
        }
    }


    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // after 90 degree rotation rows become col and col become rows
        vector<vector<char>> ans(n, vector<char> (m,'.'));

        for(int i=0; i<m; i++){
            int count = 0;

            for(int j=0; j<n; j++){
                if(box[i][j] == '#') count++;
                else if(box[i][j] == '*') {
                    ans[j][m-i-1] = '*';
                    fillStone(ans, count, j-1, m-i-1);     // fill the stone at 90 degree ratation..
                    count = 0;
                }
            }

            // if the obstacle is boundry then
            if(count > 0) {
                fillStone(ans, count, n-1, m-i-1);
            }
        }
        return ans;
    }
};