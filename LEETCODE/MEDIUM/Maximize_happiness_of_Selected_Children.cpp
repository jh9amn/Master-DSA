#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        
        for(int i=0; i<happiness.size(); i++){
            pq.push(happiness[i]);
        }
        
        int counter = 0;
        long long res = 0;
        while(k-- && !pq.empty()){
            int val = pq.top();
            pq.pop();
            
            val -= counter;
            val = max(val , 0);
            res += val;
            
            counter++;
        }
        return res;
        
    }
};



int main(){


}