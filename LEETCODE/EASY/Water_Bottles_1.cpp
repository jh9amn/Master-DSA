#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Approach 1 T.C = O(log(numBottles))
        // int ans = numBottles;
        // int rem = 0;
        // while( numBottles >= numExchange){
        //     rem = numBottles % numExchange;
        //     int finish = numBottles / numExchange;
        //     ans += finish;
        //     numBottles = finish + rem;
        // }
        // return ans;


        // Approach 2 T.C = O(1)
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};
int main(){}