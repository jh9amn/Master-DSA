#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
//         vector<int> v(26,0);
//         for(int i=0; i<s.size(); i++){
//             v[s[i]- 'a']++;
//         }
        
//         for(int i=0; i<order.size(); i++){
//             int idx = order[i] - 'a';
//             if(v[idx] > 0){
//                 while(v[idx]--){
//                     ans += order[i];
//                 }
//                 v[idx] = -1;
//             }
//         }
        
//         for(int i=0; i<s.size(); i++){
//             if(v[s[i] - 'a'] != -1) ans += s[i];
//         }
//      return ans;
        
        
        // second Method Using Custom Sorting
        // T.C = O(NlogN)   S.C = O(26) ~ O(1)
        vector<int> cusOrder(26,-1);
        int step = 1;
        // Here storing which char comes First
        for(int i=0; i<order.size(); i++){
            cusOrder[order[i] - 'a'] = step;
            step++;
        }
        
        // sort whose come after then remain same
        sort(s.begin(), s.end(), [&cusOrder] (char a, char b){
            return cusOrder[a - 'a'] < cusOrder[b - 'a'] ? true : false;
        });
        return s;
    }
};


int main(){


}