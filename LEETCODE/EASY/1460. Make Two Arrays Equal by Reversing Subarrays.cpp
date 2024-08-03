#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it : target){
            mp[it]++;
        }  

        for(auto it : arr){
            if(mp.find(it) == mp.end()) return false;
            mp[it]--;
            if(mp[it] == 0) mp.erase(it);
        } 

        return true;   
    }
};