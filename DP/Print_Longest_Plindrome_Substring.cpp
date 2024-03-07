#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if( n == 1) return s;
        string ans = "";
        int maxLen = 0;
        for(int i=0; i<n; i++){
            // for odd length palindrome
            int l = i;
            int r = i;
            while( l>=0 && r < n && s[l] == s[r]){
                // find the current palimdrome length
                int currLen = r - l + 1;
                if( currLen > maxLen) {
                    ans = s.substr(l, currLen);
                    maxLen = currLen;
                }
                l--;
                r++;
            }
            
            // for even length palindeome
            l = i;
            r = i+1;
            
            while( l>=0 && r < n && s[l] == s[r]){
                // find the current palimdrome length
                int currLen = r - l + 1;
                if(currLen > maxLen) {
                    ans = s.substr(l, currLen);
                    maxLen = currLen;
                }
                l--;
                r++;            
            }
        }
        return ans;
        
    }
};



int main(){

}