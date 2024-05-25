#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(set<string> &st, string &s, string &currWord, vector<string> &ans, int i) {
        if(i == s.size()){
            ans.push_back(currWord);
            return ;
        }
        
        for(int j = i; j<s.size(); j++){
            string temp = s.substr(i, j - i +1);
                        
            if(st.count(temp)){     // valid word
                
                string back = currWord;

                if(!currWord.empty()){
                    currWord += " ";
                }
                currWord += temp;
                
                solve(st, s, currWord, ans, j+1);    // take
                currWord = back;                        // not take
                
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        
        for(auto word : wordDict){
            st.insert(word);
        }
        
        string currWord = "";
        vector<string> ans;
        
        solve(st, s, currWord, ans, 0);
        
        return ans;
        
    }
};


int main(){}