#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(auto c : num){
            // st.top() > c then remove while k--
            while(!st.empty() and k > 0 and c < st.top()){
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        // Safety Check if not any char remove 
        // means that all the top ele in stack is smaller then 
        while(k--){
            st.pop();
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        // To bring it in real form
        reverse(ans.begin(), ans.end());
        
        // find the first occurence of non zero number from the start after reversing
        int i;
        int n = ans.size();
        for(i=0; i<n; i++){
            if(ans[i] != '0'){
                break;
            }
        }
        
        // removing 0 from start 
        ans = ans.substr(i,n-i);
        return ans.size() == 0 ? "0" : ans;
    }
};



int main(){


}