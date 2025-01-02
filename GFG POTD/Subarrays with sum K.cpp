#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int count = 0;
        int n = arr.size();
        
        /* brute force **/
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int sum = 0;
                for(int p=i; p<=j; p++) {
                    sum += arr[p];
                }
                
                if(sum == k) count++;
            }
        }
        return count;
        
        /* better */
        
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += arr[j];
            }
            if(sum == k) count++;
        }
        return count;
        
        
        /* optimal */
        
        // T.C = O(N * LogN)
        // S.C= O(N)
        unordered_map<int, int> mp;   //  subarray, cnt
        
        //To include subarrays starting from the beginning, initialize the map with
        mp[0] = 1;
        
        int prefixSum = 0;
        for(int i=0; i<n; i++) {
            prefixSum += arr[i];
            int remove = prefixSum - k;
            if (mp.find(remove) != mp.end()) {
                count += mp[remove]; // Add the frequency of the required prefix sum
            }
            mp[prefixSum]++;
        }
        return count;
    }
};