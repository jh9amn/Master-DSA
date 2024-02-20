//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    // bool solve(string s, unordered_map<string,int> &mp, int idx){
    //     if(idx >= s.size()) return true;
            
    //     for(int i=idx; i<s.size(); i++){
    //         string a = s.substr(idx,  i - idx + 1);
    //         if(mp.find(a) != mp.end()){
    //             if(solve(s, mp, i + 1)) return true;
    //         }
    //     }
    //     return false;
    // }
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_map<string,int> mp;
        for(int i=0; i<dictionary.size(); i++){
            mp[dictionary[i]]++;
        }
        
        function <bool(int) > solve = [&](int idx){
            if(idx >= s.size()) return true;
            
            for(int i=idx; i<s.size(); i++){
                string a = s.substr(idx,  i - idx + 1);     // pos , len
                if(mp.find(a) != mp.end()){
                    if(solve(i + 1)) return true;
                }
            }
            return false;
        };
        
        if(solve(0)) return true;
        return false;
    }


    // with dp
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        int dp[1100];
        memset(dp, -1, sizeof dp);
        unordered_map<string,int> mp;
        for(int i=0; i<dictionary.size(); i++){
            mp[dictionary[i]]++;
        }
        
        function <int (int) > solve = [&](int idx){
            if(idx >= s.size()) return 1;
            if(dp[idx] != -1) return dp[idx];
            
            for(int i=idx; i<s.size(); i++){
                string a = s.substr(idx,  i - idx + 1);
                if(mp.find(a) != mp.end()){
                    if(solve(i + 1)) return dp[idx] = 1;
                }
            }
            return dp[idx] =  0;
        };
        
        if(solve(0)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends