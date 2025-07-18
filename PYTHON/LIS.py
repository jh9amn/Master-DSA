class Solution1(object):
    def lengthOfLIS(self, nums):
        n = len(nums)
        dp = [[-1] * (n + 1) for _ in range(n + 1)]

        def solve(i, prev_idx):
            if i == n:
                return 0

            if dp[i][prev_idx + 1] != -1:
                return dp[i][prev_idx + 1]

            take = 0
            if(prev_idx == -1 or nums[i] > nums[prev_idx]):
                take = 1 + solve(i+1, i)
            skip = solve(i+1, prev_idx)

            dp[i][prev_idx + 1] = max(take, skip)
            return dp[i][prev_idx + 1]
        
        return solve(0, -1)
    
######################################################################

from functools import lru_cache
class Solution2(object):
    def lengthOfLIS(self, nums):
        n = len(nums)

        def solve(i, prev_idx):
            if i == n:
                return 0

            take = 0
            if(prev_idx == -1 or nums[i] > nums[prev_idx]):
                take = 1 + solve(i+1, i)
            skip = solve(i+1, prev_idx)

            return max(take, skip)
        
        return solve(0, -1)

######################################################################
sol1 = Solution1()
sol2 = Solution2()
print(sol1.lengthOfLIS([3,5,6,2,5,4,19,5,6,7,12]))  # Output: 6 ✅
print(sol2.lengthOfLIS([3,5,6,2,5,4,19,5,6,7,12]))  # Output: 6 ✅