#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

    // USING STRING
    string duplicates(string s){
    string c;
    for(int i=0; i<s.size(); i++){
    if(s[i] != s[i+1]) c.push_back(s[i]);
    } return c;
    }


// USING STACK
void removeDuplicates(string s){
    stack<char> st;
    st.push(s[0]);
    for(int i=1; i<s.size(); i++){
     if(s[i] != st.top())   st.push(s[i]);
    }
    s = "";
    while(st.size() > 0){
        s += st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}

int main(){
    string s = "aaabbbbbccaabcccfffggg";
    removeDuplicates(s);
    cout<<duplicates(s);
}



