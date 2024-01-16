#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    // Momoiztion   Tc = O(n), Sc=O(n)
    ll fm( int n, vector<int> &v, vector<int> &dp){
        if( n == 0) return v[0];
        if( n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int pick = v[n] + fm(n-2, v, dp);
        int notPick = 0 + fm(n-1, v, dp);

        return dp[n] =  max(pick, notPick); 
    }

    // Tabulaion  Tc = O(n), Sc=O(n);
    ll ft( int n, vector<int> &v){
        vector<int> dp(n+1,0);
        dp[0] = v[0];

        for(int i=1; i<=n; i++){
            int pick = v[i];  
                if(i > 1 ) pick += dp[i-2];

            int notPick = 0 + dp[i-1];

            dp[i] = max(pick , notPick);
        }
        return dp[n];
    }

    // Space Optimization Of tabulation  
    // Tc = O(n), Sc = O(1)
    ll fto( int n, vector<int> &v){
        ll prev = v[0];           // dp[0]  = v[0]
        ll prev2 = 0;          // dp[-1] = 0

        for(int i=1; i<=n; i++){
            ll pick = v[i];  
                if(i >= 2 ) pick += prev2;

            ll notPick = 0 + prev;

            ll curr = max (pick , notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    
    ll rob(vector<int>& house) {
        int n = house.size();
        if(n == 1) return house[0];  // if there is only one house then there no any adjecent house so return house[0]
        vector<int> temp1;
        vector<int> temp2;

        for(int i=0; i<n; i++){
            // can't robery in start house and last house at same time
            // so finding the max of leaving the start house and also max of leaving the last house 
            // return max from both these case values;
            if( i!= 0) temp1.push_back(house[i]);
            if( i!=n-1) temp2.push_back(house[i]);
        }
        

        int x = temp1.size();
        int y = temp2.size();

        return max(fto(x-1,temp1), fto(y-1,temp2));
    }
};


int main(){

}