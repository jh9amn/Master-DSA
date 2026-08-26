#include<bits/stdc++.h>
using namespace std:

int main() {}

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // sliding window
        int n = s.size();
        int once = 0;
        int i = 0, j = 0;
        string ans = "";

        // TC = O(n*n)
        while(j < n) {  // O(n)
            if(s[j] == '1') once++;

            // shrink window
            while(once > k or s[i] == '0'){
                if(s[i] == '1') {
                    once--;
                } 
                i++;
            }

            if(once == k){
                string ss = s.substr(i, j-i+1); // O(n)
                if(ans.empty() || ans.length() > j-i+1 ||
                (ans.length() == ss.length() && ans > ss)) {
                    ans = ss;
                }
            }
            j++;
        }
        return ans;
    }
};




class Solution {
public:
    int countOnce(string &s) {
        int cnt = 0;
        for(auto it : s) {
            if(it == '1'){
                cnt++;
            }
        }
        return cnt;
    }

    // Brute force 
    // TC ~ O(n) × O(n) × O(n) = O(n^3)
    string shortestBeautifulSubstring(string s, int k) {
        // brute force 
        int len = k;
        int n = s.size();

        string ans = "";
        // n
        while(len <= n) {
            int i=0;
            /*
            s = "1011", k = 2
            i <= n-len
            i = 4-2 = 2     // last window index
            */
            while(i <= n-len){      // n
                string ss = s.substr(i, len);      
                int once = countOnce(ss);       // n
                if(once == k) {
                    if(ans.empty() or ss < ans) {
                        ans = ss;
                    }
                }
                i++;
            }
            len++;
            if(!ans.empty()) return ans;
        }
        return "";
    }
};
