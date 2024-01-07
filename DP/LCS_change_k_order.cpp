//  https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

// this is for when the input in integer 
#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
int dp[2010][2010][10];
int f(vector<int> &s1, vector<int> &s2, int i, int j, int k){
    if(i >= s1.size() || j >= s2.size()) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(s1[i] == s2[j]) return dp[i][j][k] = 1+f(s1,s2,i+1,j+1,k);  // no need to change
    else{
        if(k>0) return dp[i][j][k] = max({1+f(s1,s2,i+1,j+1,k-1), f(s1,s2,i+1,j,k), f(s1,s2,i,j+1,k)});
        else return dp[i][j][k] = max(f(s1,s2,i+1,j,k), f(s1,s2,i,j+1,k));
    }
}

int main(){
	int m,n,k;
	cin>>m>>n>>k;
	memset(dp,-1,sizeof dp);
	vector<int> arr1;
	vector<int> arr2;
	for(int i=0; i<m; i++){
		int x;
		cin>>x;
		arr1.push_back(x);
	}
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		arr2.push_back(x);
	}
	cout<<f(arr1,arr2,0,0,k);
	return 0;
}

/*
input ->
5 5 1
1 2 3 4 5
5 3 1 4 2
 
output -> 3
*/