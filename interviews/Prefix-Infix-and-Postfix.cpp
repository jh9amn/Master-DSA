#include<bits/stdc++.h>
using namespace std;

class Expression {

private:
    int precedence(char c){
        if(c == '^')
            return 3;
        else if(c == '*' || c == '/')
            return 2;
        else if(c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    bool isOperand(char c) {
        return (isalpha(c) or isdigit(c));
    }

public:
    // INFIX to POSTFIX
    string infixToPostfix(string &s){
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++){

            // operand
            if (isOperand(s[i])) {
                ans += s[i];
            }

            // opening bracket
            else if (s[i] == '(')
            {
                st.push('(');
            }
        
            // closing bracket
            else if (s[i] == ')')
            {
                while (!st.empty() and st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
            }
            
            // operator
            else
            {
                if(s[i] == '^') {
                    //   ^ is right associative
                    while(!st.empty() and precedence(s[i]) < precedence(st.top())){
                        ans += st.top();
                        st.pop();
                    }
                }
                else {
                    //    + - * / are left associative
                    while(!st.empty() and precedence(s[i]) <= precedence(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        
        // remaining operators in the stack
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }



/*
    **INFIX to PREFIX**

    Ex: (A+B)*C-D+F

    Step 1: reverse the infix
        F+D-C*)B+A(
        F+D-C*(B+A)         Note: put '(' at place of ')' and viseversa
    
    Step 2: Infix to postfix
        
    Step 3: Reverse the answer 


    Infix
    ↓
    Reverse
    ↓
    Swap '(' and ')'
    ↓
    Convert to postfix
    ↓
    Reverse postfix
    ↓
    Prefix

*/

    string infixToPrefix(string &s){
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++){
            if (s[i]== '('){
                s[i] = ')';
            }
            else if (s[i] == ')') {
                s[i] = '(';
            }  
        }   

        // Remaining code same as infixToPostfix function
        // string postfix = infixToPostfix(s);
        // reverse(postfix.begin(), postfix.end());
        // return postfix;

        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++){
            if(isOperand(s[i])){
                ans += s[i];
            }

            else if(s[i] == '(') {
                st.push('(');
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) {   // pop the '(' from the stack
                    st.pop();
                }
            }
            else {
                if (s[i] == '^') {
                    while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                else {
                    while(!st.empty() && precedence(s[i]) < precedence(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

};
