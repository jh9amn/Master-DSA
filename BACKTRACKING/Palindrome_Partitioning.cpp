#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Palindrome(string s){
        int i=0, j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>&ans, vector<string>curr, int ind){
        if(ind>=s.size()){
            ans.push_back(curr);
            return;
        }
        string a="";
        for(int i=ind;i<s.length();i++){
            a+=s[i];
            if(Palindrome(a)){
                curr.push_back(a);
                solve(s, ans, curr, i+1);
                curr.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;

        solve(s, ans, curr, 0);

        return ans;
    }
};

int main(){

}