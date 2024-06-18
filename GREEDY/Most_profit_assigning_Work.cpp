#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // T.C = O(n)   S.C = O(10^5)
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int maxDifficulty = 0;
        for(int i=0; i<difficulty.size(); i++){
            maxDifficulty = max(maxDifficulty, difficulty[i]);
        }
        
        vector<int> maxProfitDiff(maxDifficulty+1,0);
        
        for(int i=0; i<difficulty.size(); i++){
            maxProfitDiff[difficulty[i]] = max(maxProfitDiff[difficulty[i]], profit[i]); // if difficulty repeat again with diff profit values
        }
        
        for(int i=1; i<=maxDifficulty; i++){
            maxProfitDiff[i] = max(maxProfitDiff[i], maxProfitDiff[i-1]);
        }
        
        
        int ans = 0;
        for(int j=0; j<worker.size(); j++){
            if(worker[j] > maxDifficulty) ans += maxProfitDiff[maxDifficulty];
            else ans += maxProfitDiff[worker[j]];
        }
        
        return ans;
    }
};

int main(){}