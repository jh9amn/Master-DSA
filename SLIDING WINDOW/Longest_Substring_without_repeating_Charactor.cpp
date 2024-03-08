#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int n = s.size();
        
        // sliding windows l = left and r = right side of window
        int l = 0;
        int r = 0;
        int maxLen = 0;
        
        while(r < n){
            // remove left side char jabtak right side char ke barabar rahta hai
            // window is shifting from the left side
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                    l++;
            }
            // else insert jab set me char duplicate char n ho and increase the window size
            // here window is shifting from the right side 
            st.insert(s[r]);
            // here storing the max length which is occure
            maxLen = max( r - l +1 , maxLen);
            r++;
        }
        return maxLen;
        
    }
};


int main(){

}