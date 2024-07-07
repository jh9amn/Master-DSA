#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        ans = numBottles;
        while(numBottles >= numExchange){
            numBottles -= numExchange;
            ans++;
            numBottles += 1;    // adding the exchanged bottle to full bottles
            numExchange += 1;   // increase the numExchange for next bottle exchange
        }
        return ans;
    }
};


int main(){

}