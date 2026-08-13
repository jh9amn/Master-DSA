#include<bits/stdc++.h>
using namespace std;

class Expression {

  string infixToPostfix(string &s){
          
    if( (s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z') || (s[i] >= '1' and s[i] <= '9')) {
      ans[i] += s[i];
    }
    else if( s[i] == '(') {
      st.push('(');
    }

    else if(s[i] == ')'){
      while(st.top() != '(') {
        ans += st.top();
      }
      st.pop();
    }

    else {
      while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
        ans += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return ans;
}
