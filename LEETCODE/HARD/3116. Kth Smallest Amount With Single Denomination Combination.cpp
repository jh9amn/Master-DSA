#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    typedef long long ll;
    ll countSmaller(ll mid, vector<int>& coins){
        int n = coins.size();
        ll correctedCnt = 0;

        // O(2^n * n * log(maxCoin))
        /*
        1 << 0  =  1    (binary: 0001)
        1 << 1  =  2    (binary: 0010)
        1 << 2  =  4    (binary: 0100)
        1 << 3  =  8    (binary: 1000)
        1 << 4  =  16   (binary: 10000)

        so;
            1 << (n-1) = 2^(n-1)
        */
        for(int exp = 1; exp <= (1 << n) - 1; exp++) {  // 2^(n-1) expressions
            ll lcm = 0;
            // odd and even expression to include and exclude
            ll order = 0;

            // n
            for(int i=0; i<n; i++) {
                if(exp & (1 << i)) {
                    order++; // have taken ith coin

                    if(lcm == 0){
                        lcm = coins[i];
                    }
                    else {
                        // log(maxCoin)
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }  

            // ever expression means do substration (exclusive)
            // odd expression means do addition (inclusive)
            if(order % 2 == 0) {    
                correctedCnt -= mid/lcm;
            } 
            else {
                correctedCnt += mid/lcm;
            }
        }
        return correctedCnt;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        ll ans = -1;

        ll l = 1;
        // max possible ele at kth idx
        ll r = (ll)(*max_element(coins.begin(), coins.end())) * k;

        // binary search (log(maxCoin * k))
        // OverAll TC = O(log(maxCoin * k) * O(2^n * n * log(maxCoin)))
        while(l<=r){
            ll mid = (r + l)/2;
            if(countSmaller(mid, coins) >= k) { // go left and find min kth smmallet ele
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }   
};