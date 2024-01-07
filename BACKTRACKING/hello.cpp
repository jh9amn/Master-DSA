#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int idx, int n, int k, vector<int> &v, vector<vector<int>> &ans){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        
        for(int i=idx; i<=n; i++){
            v.push_back(i);
            f(i+1,n,k,v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        f(1,n,k,v,ans);
        return ans;
    }
};

 int main(){

 }