#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto x : s){
            mp[x]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto x : mp){
            pq.push({x.second, x.first});
        }
        
        string ans = "";
        while(!pq.empty()){
            auto x = pq.top();
            
            for(int i=0; i<x.first; i++){
                ans += x.second;
            }
            pq.pop();
        }
        return ans;
    }
};


int main(){

}