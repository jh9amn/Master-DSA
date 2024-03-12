#include<bits/stdc++.h>
using namespace std;

// Multiplication
vector<vector<long long>> multiply(vector<vector<long long>> temp, vector<vector<long long>> v){
    vector<vector<long long>> res(2,vector<long long> (2,0));
    
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                res[i][j] += temp[i][k] * v[k][j] % 1000000007;
            }
        }
    }
    return res;
}

// Finding Fibonacci in T.C= O(lonN)
vector<vector<long long>> call(vector<vector<long long>> &v, int A){
    if(A == 1) return v;
    
    vector<vector<long long>> temp = call(v,A/2);
    if(A%2 == 0) return  multiply(temp,temp);
    
    return multiply(temp,multiply(temp,v));
}

int solve(int A) {
    vector<vector<long long>> v = {{1,1},{1,0}};
    vector<vector<long long>> temp = call(v,A);
    // Here You ca return temp[1][0] too
    return temp[0][1] % 1000000007;
}



int main(){


}