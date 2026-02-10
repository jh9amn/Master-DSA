class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        maxi = 0

        for i in range(n):
            seen = set()
            evn = 0
            odd = 0
            for j in range(i, n):
                val = nums[j]
                if val not in seen:
                    seen.add(val)
                    if nums[j] % 2 == 0:
                        evn += 1
                    else:
                        odd += 1

                if evn == odd:
                    maxi = max(j-i+1, maxi)

        return maxi