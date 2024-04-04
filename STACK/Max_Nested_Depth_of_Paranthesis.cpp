#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxDepth(string s) {
        // T.C = O(n) S.C = O(n)
        // stack<char> st;
        // int res = 0;
        // for(int i=0; i<s.size(); i++){
        //     if(s[i] == '(') st.push('(');
        //     else if(s[i] == ')') st.pop();
        //     res = max(res, (int)st.size());
        // }
        // return res;
        
        
        // T.C = O(n) S.C = (1)
        int res = 0;
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') count++;
            else if(s[i] == ')') count--;
            res = max(res, count);
        }
        return res;
    }
};



int main(){



}