//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int maxProfit(vector<int>&price){
            // Memoization not working for all test case 
            
            // int n = price.size();
            // int dp[n+1][3][3];
            // memset(dp, -1, sizeof dp);
            
            // // Here memoization not passing the last test case in GFG
            // function <int(int, int, int)> solve = [&] (int i, int buySell, int times) {
            //     if(times == 0) return 0;
            //     if(i == n) return 0;
            //     if(dp[i][buySell][times] != -1) return dp[i][buySell][times];
                
            //     if(buySell == 1){ // this time buy first (1 = buy)
            //         return dp[i][buySell][times] = max(-price[i] + solve(i+1, 0, times), solve(i+1, 1, times));
            //     }
            //     if(buySell == 0){// this time sell  (0 == sell)
            //         return dp[i][buySell][times] = max(price[i] + solve(i+1, 1, times - 1), solve(i+1, 0, times));
            //     }
            // };
            
            // return solve(0,1,2); // 0 = starting index, 1 = start with buy , 2 = how many times buy and sell
            
            // another method 
            int n = price.size();
            vector<int> temp(n,0);
            
            
            int maxi = price[n-1];
            for(int i=n-2; i>=0; i--){
                maxi = max( maxi, price[i]);
                temp[i] = max(temp[i+1], maxi - price[i]);
            }
            
            int mini = price[0];
            for(int i=0; i<n; i++){
                mini = min(price[i], mini);
                temp[i] = max(temp[i-1], price[i] - mini + temp[i]);
            }
            
            return temp[n-1];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends