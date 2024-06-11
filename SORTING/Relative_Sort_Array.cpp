#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    // Approach 1:
    // T.C = O(log(n)) + O(n)       // S.C = O(n)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//         vector<int> ans;
        
//         unordered_map<int, int> mp;
//         for(auto it : arr1){
//             mp[it]++;
//         }
        
//         sort(arr1.begin(), arr1.end());
        
//         for(int i=0; i<arr2.size(); i++){
//             if(mp.count(arr2[i])){
//                 int cnt = mp[arr2[i]];
//                 mp[arr2[i]] = 0;
                
//                 while(cnt--){
//                     ans.push_back(arr2[i]);
//                 }
//             }
//         }
        
        
//         for(int i=0; i<arr1.size(); i++){
//             if(mp[arr1[i]]){
//                 int cnt = mp[arr1[i]];
//                 mp[arr1[i]] = 0;
//                 while(cnt--){
//                     ans.push_back(arr1[i]);
//                 }
//             }
//         }
//              return ans;
    
    
        
        
    
    // Approach 2 :  using custom sorting with comparator
    unordered_map<int, int> mp;
    for(int i=0; i<arr2.size(); i++){
        mp[arr2[i]] = i;        // store arr2 with index
    }
    
    // now insert the remaining ele which are not present in arr2 but present in arr1 with index val -1
    for(int i=0; i<arr1.size(); i++){
        if(!mp.count(arr1[i])){
            mp[arr1[i]] = 1e9;
        }
    }
    
    // custom sort according to the mp
    // condition 1 : mp[a] == mp[b] means idx same then sort in ascending order return (a < b)
    // condition 2 : mp[a] < mp[b]  custom sort with arr2 index...
    
    sort(arr1.begin(), arr1.end(), [&arr1, &mp](int a, int b){
        if(mp[a] == mp[b]){
            return a < b;
        }
        return mp[a] < mp[b];
    });
    
    
    
    
        return arr1;
    }
};