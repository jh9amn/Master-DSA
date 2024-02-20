#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size() == 0) return t[0];
        
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        
        vector<int> vt(26,0);
        vector<int> vs(26,0);
        
        for(int i=0; i<s.size(); i++){
            vs[s[i] - 'a']++;
        }
        
        for(int i=0; i<t.size(); i++){
            vt[t[i] - 'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(vs[i] != vt[i]){
                return alpha[i];
            }
        }
        return t[0];
    }
};

int main(){

}