#include<bits/stdc++.h>
using namespace std;

// T.C = n-> n/2 -> n/4 -> n/8......
// T.C = O(logN)
class Solution {
public:
    // T.C = O(logN)
    double solve(double x, long n){
        if( n == 0) return 1;
        if( n == -1) return 1/x;
        
        double temp = solve(x, n/2);
        
        // even
        if(n%2 == 0) return temp * temp;
        // odd
        if(n > 0 ) return temp * temp * x;
        // negative
        return temp * temp * (1/x);
    }
    double myPow(double x, int n) {
       return solve(x,n);
        
    }
};

int main(){

}