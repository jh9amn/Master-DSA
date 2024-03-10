#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Brute force apporoach
        int mini = prices[0];
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++){
            int cost = prices[i] - mini;
            mini = min( mini, prices[i]);
            maxProfit = max(maxProfit, cost);
        }
        return maxProfit;
    }
};


int main(){

}