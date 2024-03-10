#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memoization  T.C = (N*2)   S.C = O(N*2) + O(N)
//     int dp[n+1][2];
//     int f(vector<int> &prices, int i, bool on){
        
//         // if you only buy and never sell then profit is 0
//         if(i == prices.size()) return 0;
        
//         int maxProfit = INT_MIN;
        
//         if(dp[i][on] != -1) return dp[i][on];
        
//         // on == true means buy time
//         if(on == true) { //         buy                                 not buy
//             maxProfit = max(-prices[i] + f(prices, i+1, false), 0 + f(prices, i+1, true));
//         }
//         // on == false means sell time
//         else {          //          sell                                not sell
//             maxProfit = max( prices[i] + f(prices, i+1, true), 0 + f(prices, i+1, false));
//         }
//         return dp[i][on] =  maxProfit;
//     } 

    int maxProfit(vector<int>& prices) {
        // memoiztion call
        // return f(prices,0,true);  // initially no transaction so true means you can buy now and false means you can sell.
        
        
        // Tabulation ( Bottom Up)
        // int n = prices.size();
        // int dp[n+1][2];
        // memset(dp,0, sizeof dp);
        // dp[n][0] = dp[n][1] = 0;
        // for(int idx = n-1; idx >= 0; idx--){
        //     for(int on = 1; on >= 0; on--){
        //         int maxProfit = 0;
        //         if(on == true) { //         buy                                 not buy
        //             maxProfit = max( -prices[idx] + dp[idx + 1][false] , 0 + dp[idx + 1][true]);
        //         }
        //         // on == false means sell time
        //         else {          //          sell                                not sell
        //             maxProfit = max( prices[idx] + dp[idx + 1][true] , 0 + dp[idx + 1][false]);
        //         }
        //         dp[idx][on] = maxProfit;
        //     }
        // }
        // return dp[0][1];
        
        
        // Tabulation Space Optimization Using 2 size Arrays..
        // int n = prices.size();        
        // vector<int> ahead(2,0), curr(2,0);
        // ahead[0] = ahead[1] = 0;
        // for(int idx = n-1; idx >= 0; idx--){
        //     for(int on = 1; on >= 0; on--){
        //         int maxProfit = 0;
        //         if(on == 1) { //         buy                                 not buy
        //             maxProfit = max( -prices[idx] + ahead[0] , 0 + ahead[1]);
        //         }
        //         // on == false means sell time
        //         else {          //          sell                                not sell
        //             maxProfit = max( prices[idx] + ahead[1] , 0 + ahead[0]);
        //         }
        //         curr[on] = maxProfit;
        //     }
        //     ahead = curr;
        // }
        // return ahead[1];
        
        
        // Tabulation Space Optimization Using 4 variables
        int n = prices.size();        
        int aheadNotBuy, aheadBuy, currNotBuy, currBuy;
        aheadNotBuy = aheadBuy = 0;
        for(int idx = n-1; idx >= 0; idx--){
                         //          sell                      not sell
                currNotBuy = max( prices[idx] + aheadBuy , 0 + aheadNotBuy);
            
            
                        //        buy                          not buy
                currBuy = max( -prices[idx] + aheadNotBuy , 0 + aheadBuy);
       
                aheadBuy = currBuy;
                aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};


int main(){


}