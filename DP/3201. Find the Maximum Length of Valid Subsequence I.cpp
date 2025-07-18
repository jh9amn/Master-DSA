class Solution {
public:
/*
    if even + even = even -> even % 2 = 0
    if odd + odd = even -> even % 2 = 0
    if even + odd = odd -> odd % 2 = 1

    # pick all even subsequency % 2 = 0
    # pick all odd subsequency % 2 = 0
    # alternative parity subsequency number % 2 = 1

*/
    int maximumLength(vector<int>& nums) {
        int countEven = 0;
        int countOdd = 0;
        int alternating = 1;

        for(auto it : nums) {
            if(it % 2 == 1) {
                countOdd++;
            }
            else{
                countEven++;
            }
        }

        int parity = nums[0] % 2;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] % 2 != parity) {
                alternating++;
                parity = !parity;
            }
        }
        
        return max({countEven, countOdd, alternating});
    }
};

/**********************************************************************************************/

/* Using LIS Approach */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp0(n, 1);  // mod = 0
        vector<int> dp1(n, 1);  // mod = 1
        int maxiLen = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++) {
                int mod = (nums[i] + nums[j]) % 2;  
                // mod = 0  
                if(mod == 0){   
                    dp0[i] = max(dp0[i], dp0[j] + 1);
                    maxiLen = max(maxiLen, dp0[i]); 

                }
                // mod = 1
                else {  
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                    maxiLen = max(maxiLen, dp1[i]);
                }
            }
        }

        return maxiLen;
    }
};

/* To look code more clear, we can use 2D Array instead of using two saperate arrays */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int> (n, 1));
        int maxiLen = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++) {
                int mod = (nums[i] + nums[j]) % 2;  
                // mod = 0 or 1 
                dp[mod][i] = max(dp[mod][i], dp[mod][j] + 1);
                maxiLen = max(maxiLen, dp[mod][i]); 
            }
        }

        return maxiLen;
    }
};
