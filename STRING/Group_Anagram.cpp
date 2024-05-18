#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        // mark sorted string indicator and push_value who look like that that
        map<string,vector<string>> mp;
        
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            
            if(mp.find(s) != mp.end()){
                // mill gya
                mp[s].push_back(strs[i]);
            }
            else{
                vector<string> dummy;
                dummy.push_back(strs[i]);
                mp[s] = dummy;
            }
        }
        
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};


int main(){

}