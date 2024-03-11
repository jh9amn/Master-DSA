#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++){
            v[s[i]- 'a']++;
        }
        
        for(int i=0; i<order.size(); i++){
            int idx = order[i] - 'a';
            if(v[idx] > 0){
                while(v[idx]--){
                    ans += order[i];
                }
                v[idx] = -1;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            if(v[s[i] - 'a'] != -1) ans += s[i];
        }
        
        return ans;
    }
};


int main(){


}