#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int n;
    int dp[100001][3];
    int binarySearchToFindValidIndex(vector<vector<int>>& events, int endTime){
        int s = 0;
        int l = n-1;
        int validIdx = n;

        while(s <= l){
            int mid = s + (l-s) / 2;

            if(events[mid][0] > endTime){
                validIdx = mid;
                l = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return validIdx;
    }
    int solve(vector<vector<int>>& e, int i, int count){
        if(count == 2 || i >= n) return 0;

        if(dp[i][count] != -1) return dp[i][count];
        
        int nextValidIdx = binarySearchToFindValidIndex(e, e[i][1]); 

        int take = e[i][2] + solve(e, nextValidIdx, count+1);
        int not_take = solve(e, i+1, count);

        return dp[i][count] = max(take, not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {

        /*** Brute force **/
        // int n = events.size();
        // int maxSum = 0;

        // // Check all pairs of events
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         // First event
        //         int start1 = events[i][0];
        //         int end1 = events[i][1];
        //         int value1 = events[i][2];

        //         // Second event
        //         int start2 = events[j][0];
        //         int end2 = events[j][1];
        //         int value2 = events[j][2];

        //         // Check if the two events are non-overlapping
        //         if (end1 < start2 || end2 < start1) {
        //             maxSum = max(maxSum, value1 + value2);
        //         } else if (i == j) { // Single event case
        //             maxSum = max(maxSum, value1);
        //         }
        //     }
        // }
        // return maxSum;

        /*** Dp + Bianry search to find valid Index **/
        sort(events.begin(), events.end());
        n = events.size();
        memset(dp, -1, sizeof(dp));
        return solve(events, 0, 0);
    }
};