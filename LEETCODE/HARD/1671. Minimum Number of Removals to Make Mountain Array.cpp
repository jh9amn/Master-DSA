#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n,1);
        vector<int> LDS(n,1);


        // Longest Increasing Sequence
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Longest Decreasing Sequence
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        /*
        Removable for left side : (i+1) - LIS[i]
        Removable for roght side : (n-i) - LDS[i]       
                        (n-i) gives no of ele on right side from i
                        (i+1) give no of ele on left side from i
        total ele to remove = (i+1) - LIS[i] + (n-i) - LDS[i];
                            = n - LIS[i] - LDS[i] + 1 
        */    

        int ans = n;
        // finding the size after removing LIS and LDS lengths
        for(int i=1; i<n-1; i++){
            if(LIS[i] > 1 && LDS[i] > 1){
                ans = min(ans, n - (LIS[i] + LDS[i] - 1));
            }
        }
        return ans;
    }
};