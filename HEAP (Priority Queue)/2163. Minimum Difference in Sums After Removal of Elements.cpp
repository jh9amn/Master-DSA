/* 

# divide there array into 3 parts 
# and remove one part sequence of size n
# we have to find min difference 
# so, the last two part of size 2n in which
# the first part ele sum must be smaller
# and the last part ele sum must be greater 
# the we get min difference sum

# I have to remove that n size ele after which the remaining array has the length of 2n 
# where (first n sequence sum - second n sequence sum) give min value..

** Observation **
# min left array -> which store min sum of ele of size n from left side (min heap)
# max right array -> which store max sum of ele of size n from rigth side (max heap)
# min differece of leftSide array and rightSide array 

*/

#include<bits/stdc++.h>
using namespace std:

int main() {}

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int totalSize = nums.size();  // 3n = total size of nums..

        vector<long long> leftMinSum(totalSize, 0);
        vector<long long> rightMaxSum(totalSize, 0);

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 1: Track min sum of n elements from left using max-heap
        long long leftSum = 0;
        for(int i=0; i<2*n; i++) {      // min cumulative sum of size n from left in (range 0 -> 3n - n -1)
            maxHeap.push(nums[i]);
            leftSum += nums[i];
            if(maxHeap.size() > n) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            if(i >= n-1) {
                leftMinSum[i] = leftSum;
            }
        }

        // Step 2: Track max sum of n elements from right using min-heap
        long long rightSum = 0;
        for(int i=totalSize-1; i>=n; i--) {     // max cumulative sum of size n from right in (range 3n-1 -> n) 
            minHeap.push(nums[i]);
            rightSum += nums[i];
            if(minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if(i <= totalSize - n){
                rightMaxSum[i] = rightSum;
            }
        }
        
        // Step 3: Compute minimum difference
        long long mini = LLONG_MAX;
        for(int i=n-1; i<totalSize - n; i++) {
            mini = min(leftMinSum[i] - rightMaxSum[i+1], mini);
        }
        
        return mini;
    } 
};
