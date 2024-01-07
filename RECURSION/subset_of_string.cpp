#include<bits/stdc++.h>
using namespace std;
void f(string s,string ans, int i){
    if(s.size() == i){
        cout<<ans<<endl;
        return;
    }
    f(s,ans+s[i],i+1);
    f(s,ans,i+1);
}

void storeSubset(string s,string ans, int i,vector<string> &v){
    if(s.size() == i){
        v.push_back(ans);
        return;
    }
    storeSubset(s,ans,i+1,v);
    storeSubset(s,ans+s[i],i+1,v);
}

int main(){
    string s = "abc";
    string ans = "";
    f(s,ans,0);

    // storing in vector
    vector<string> v;
    storeSubset(s,ans,0,v);
    for(auto ele : v){
        cout<<ele<<" ";
    }
}