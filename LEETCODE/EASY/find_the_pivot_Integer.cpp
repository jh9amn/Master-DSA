#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        // Method 1:
        int leftSum = 0;
        int rightSum = 0;
        for(int i=1; i<=n; i++){
            // sum till ith number
            int leftSum = (i * (i+1))/2 ;
            // total sum of nth number
            int totalSum = (n * (n+1))/2;
            // sum till (i -> n) number
            int rightSum = totalSum - leftSum + i;
            // if left sum == right sum return i
            if(leftSum == rightSum) return i;
        }
        return -1;
        
        
//         Method 2 but sqrt can be in double: 
//         int x = sqrt(n * (n + 1) / 2);
//         if (x % 1 != 0)
//             return -1;
//         else
//             return int(x);
//          return -1;
    }
};



int main(){


}