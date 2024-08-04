#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Brute force ...
        // long long int mod = 1e9 + 7;
        // vector<int> subArray;
        // for(int i=0; i<n; i++){
        //     int sum =  0;
        //     for(int j=i; j<n; j++){
        //         sum += nums[j];
        //         subArray.push_back(sum);
        //     }
        // }
        

        // sort(subArray.begin(), subArray.end());         // N * (N+1) / 2  elements
 
        // long long int ans = 0;
        // for(int i=left-1; i<=right-1; i++){
        //     ans += subArray[i];
        // }
        // return ans % mod;


        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }

        long long int ans = 0;
        long long int mod = 1e9 + 7;

        for(int i=0; i<right; i++){
            auto it = pq.top();
            int val = it.first;
            int idx = it.second;
            pq.pop();
            if(i >= left - 1){
                ans = (ans + val ) % mod;
            }
            if(idx+1 < n) {
                idx++;
                pq.push({nums[idx] + val, idx});
            }
        }
        return ans;
    }
};