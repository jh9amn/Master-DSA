#include<bits/stdc++.h>
using namespace std;


// 4D Dp Question...
int dp[101][27][101][101];   // 'z' - 'a' == 25
class Solution {
public:             // TC => O(n * 26 * n * k) => O( n2 * k)
    int solve(string &s, int i, int prev_char, int freq, int k){
        // Base Case
        if( k < 0) return INT_MAX;
        if( i >= s.size()) return 0;
    
        if(dp[i][prev_char][freq][k] != -1) return dp[i][prev_char][freq][k];
        
        // delete
        int del_i = solve(s, i + 1, prev_char, freq, k - 1);
        
        // Keep then
        int keep_i = 0;
        // if prev_char != curr_char
        if(s[i] - 'a' != prev_char){
            keep_i = 1 + solve(s, i + 1, s[i] - 'a', 1, k);         // and Now Freq Become 1 for the next Char
        } 
        else {  // if the char have freq more than 1 or 9 or 99 then one more number will be added
            int one_More_Number_Add = 0;
            if(freq == 1 || freq == 9 || freq == 99){
                one_More_Number_Add = 1; 
            }
            keep_i = one_More_Number_Add + solve(s, i + 1, prev_char, freq + 1, k);
        }
        return dp[i][prev_char][freq][k] =  min(keep_i, del_i);
        
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof (dp));
        return solve(s, 0 , 26, 0 , k);   // s, idx, prev_char, freq, k
    }
};

int main(){

}