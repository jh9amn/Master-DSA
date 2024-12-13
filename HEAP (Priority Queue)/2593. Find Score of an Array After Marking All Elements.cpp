#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    long long findScore(vector<int>& nums) {

        long long ans = 0;
        int n = nums.size();

        unordered_set<int> st;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int val = it.first;
            int idx = it.second;

            // if idx is not marked
            if(!st.count(idx)){
                ans += val;
                st.insert(idx);

                if(idx > 0){
                    st.insert(idx-1);
                }

                if(idx < n-1){
                    st.insert(idx+1);
                }
            }
        }

        return ans;
    }
};