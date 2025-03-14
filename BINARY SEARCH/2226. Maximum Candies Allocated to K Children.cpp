#include<bits/stdc++.h>
using namespace std;
int main(){}


// class Solution {
// public:
//     int binarySearch(int low, int high) {
//         while(low <= high) {
//             int mid = (low + high) / 2;


//         }
//     }
//     int maximumCandies(vector<int>& candies, long long k) {
//         int n = candies.size();
//         int maxiCandi = 0;
//         for(int i=0; i<n; i++){
//             maxiCandi = max(maxiCandi, candies[i]);
//         }
//         // brute force
//         for(int i=maxiCandi; i>=1; i--) {
//             int distribute = 0;
//             for(int j=0; j<n; j++){
//                 distribute += candies[j] / i;
//             }

//             if(distribute >= k){
//                 return i;
//             }
//         }
//         return 0;
//     }
// };


// TC = O(N * log(h))
class Solution {
public:
    bool canDistribute(vector<int> &candies, int distribute, long long k) {
        long long count = 0;
        for (int c : candies) {     // O(n)
            count += c / distribute; 
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxiCandi = *max_element(candies.begin(), candies.end());

        int l = 1, h = maxiCandi;

        int ans = 0;
        while(l <= h){      // O(log(h))
            int mid = l + (h - l) / 2;

            if(canDistribute(candies, mid, k)) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans;
    }
};