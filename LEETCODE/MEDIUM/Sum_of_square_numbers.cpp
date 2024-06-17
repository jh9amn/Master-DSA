#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        // Brute force
//         long long sqrtVal = sqrt(c);
//         for(long long i=0; i<=sqrtVal; i++){
//             for(long long j=0; j<=sqrtVal; j++){
//                 long long _j = j*j;
//                 long long _i = i*i;
                
//                 if(_i + _j == c) return true;
//             }
//         }
//         return false;
        
        if(c == 3 ) return false;
        long long a = 0;
        long long b = (long long)sqrt(c);
        while(a <= b){
            long long t = a*a + b*b;
            
            if(t > c) {
                b--;
            }
            else if(t < c) {
                a++;
            }
            else return true;
        }
        return false;
    }
};


int main(){

}