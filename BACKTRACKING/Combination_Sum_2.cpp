#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    
    void combi(vector<int> &candidates, int target, vector<int> &v, int idx){
        // Base Case
        if(target == 0) {
            ans.push_back(v);
            return;
        }        
        if(idx == candidates.size()) return;
        
        // Pick
        if(candidates[idx] <= target){
            v.push_back(candidates[idx]);
            combi(candidates, target - candidates[idx], v, idx + 1);
            v.pop_back();
        }
        
        // Avoid
        int j = idx + 1;        // if the same element is repeating the skip that element
        while( j < candidates.size() && candidates[j] == candidates[j - 1]) j++;
        combi(candidates, target, v, j);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        ans.clear();
        combi(candidates, target, v, 0);
        return ans;
    }
};
int main(){

}