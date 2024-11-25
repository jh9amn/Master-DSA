#include<bits/stdc++.h>
using namespace std;
int main(){}


/**
1) if there is atleast one zero then all negative ele will removed
2) if there are even number of negative ele then all can become positive
3) if there is odd number of negative then all become positive except one ele.. so choise the smallest ele to eleminate
4) if all positive ele then do not apply any operation, just sun all ele and 

*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int zero = 0;
        int neg = 0;

        int m = matrix.size();
        int n = matrix[0].size();
        long long ans = 0;
        int miniEle = INT_MAX;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] < 0) neg++;
                if(matrix[i][j] == 0) zero++;
                miniEle = min(miniEle, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }


        if(zero) return ans;
        if(neg % 2 != 0) return ans - 2*miniEle;
        return ans;
    }
};