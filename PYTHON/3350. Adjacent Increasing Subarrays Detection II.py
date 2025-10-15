class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ## trying with count and precount

        n = len(nums)
        precnt = 0
        cnt = 1

        ans = 0
        for i in range(1,n):
            if nums[i] > nums[i-1]:
                cnt += 1
            else:
                precnt = cnt
                cnt = 1

            ans = max(ans, min(cnt, precnt))
            ans = max(ans, cnt//2)

        return ans
