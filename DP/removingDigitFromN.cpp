#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

vector<int> get_digit(int n){
vector<int> result;
    while(n > 0){
        if( n%10 != 0){
            result.push_back(n%10);
        } n/=10;
    } return result;
}

vector<int> dp;
int f(int n){
    if(n==0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> d = get_digit(n);

    int count = INT_MAX;
    for(int i=0; i<d.size(); i++){
        count = min(count, f(n-d[i]));
    }
    return dp[n] = 1+count;
}

int main(){
    dp.clear();
    dp.resize(1000005,-1);
    cout<<f(27)<<endl;
}