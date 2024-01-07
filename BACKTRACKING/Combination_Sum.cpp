#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sum( vector<int>& candidates, int target, int i, vector<vector<int>> &ans, vector<int> &v){
       
        if( i == candidates.size()) {
            if(target == 0) ans.push_back(v);
            return;
        }
        
        if(candidates[i] <= target){
            v.push_back(candidates[i]);
            sum(candidates, target - candidates[i], i, ans, v);
            v.pop_back();
        }
        
        sum(candidates, target, i + 1, ans, v);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sum(candidates, target, 0, ans, v);
        return ans;
    }
};

int main(){
}