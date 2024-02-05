#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
// Using map ....
//         unordered_map<char,int> mp;
//         for(int i=0; i<s.size(); i++){
//             mp[s[i]]++;
//         }
        
//         for(int i=0; i<s.size(); i++){
//             auto x = mp.find(s[i]);
//             if(x->second == 1) return i;
//         }
//         return -1;
        
        
// Using Array oF 26 size....
        int arr[26];
        for(int i=0; i<s.size(); i++){
            arr[s[i] - 'a']++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(arr[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};


int main(){

}