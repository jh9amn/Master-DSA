#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x; // first ans = x
        n -= 1;     

        while(n-->0){
            ans = (ans + 1) | x; 
        }   
        return ans;    
    }
};


class Solution {
public:
    long minEnd(int n, int x) {
        long result = x;
        long remaining = n - 1;
        long position = 1;

        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }

        return result;
    }
};
