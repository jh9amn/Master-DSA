#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m);
        vector<vector<int>> ans = matrix;
        for(int i=0; i<m; i++){
            set<int, greater<int>> st;
            for(int j=0; j<n; j++){
                st.insert(matrix[j][i]);
            }
            
            for( auto it = st.begin();  it != st.end(); it++){
                v[i] = *it;
                break;
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ans[j][i] == -1) ans[j][i] = v[i];
            }
        }
        
        return ans;
    }
};


int main(){

}