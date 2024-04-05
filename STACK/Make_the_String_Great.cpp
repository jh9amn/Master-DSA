#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        
        // T.C = O(1) and S.C = O(n)
        // stack<char> stk;
        // for (char &c : s) {
        //     if (!stk.empty() && abs(c - stk.top()) == 32) { // Check if characters form a bad pair
        //         stk.pop(); // Pop the character from the stack
        //     } else {
        //         stk.push(c); // Push the character onto the stack
        //     }
        // }
        // string result = "";
        // while (!stk.empty()) {
        //     result = stk.top() + result; // Build the result string by prepending characters from the stack
        //     stk.pop();
        // }
        // return result;
        
        
        // T.C = O(n) S.C = O(1)
        string ans = "";
        for(int i=0; i<s.size(); i++){
            int len = ans.size();
            if(len > 0 and abs(s[i] - ans[len-1]) == 32) ans.pop_back();
            else ans += s[i];
        }
        return ans;
    }
};



int main(){


}