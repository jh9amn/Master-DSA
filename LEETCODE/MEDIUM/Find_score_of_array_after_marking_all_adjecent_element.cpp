#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        // here map is not used because map hasnot more than one no of val with different keys
        // so that's why I use priority_queue ans it's is also efficient as map
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        long long ans = 0;
        
        // storing every ele with their index
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }
        
        // here marking idx - 1 , idx, idx + 1 values as they donot take in other iteration
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int val = it.first;
            int key = it.second;
            
            // if they are not marked yet, marked that index as well as adjecent index too and add the value at index to ans
            if(st.find(key) == st.end()){
                ans += val;
                st.insert(key);
                // key - 1 don't go out of bound
                if(key - 1 >= 0){
                    st.insert(key - 1);
                }
                // key + 1 don't go out of bound
                if(key + 1 < n){
                    st.insert(key+1);
                }
            }
        }
        return ans;
    }
};


int main(){

}