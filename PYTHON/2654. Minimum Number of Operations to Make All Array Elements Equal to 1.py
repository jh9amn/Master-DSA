class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        def gcd(a, b):
            if a % b == 0:  return b
            return gcd(b%a, a)

        ones = 0
        g = 0

        for x in nums:
            g = gcd(g, x)
            ## 1s there 
            if x == 1: ones += 1

        if g > 1: return -1         ## if gcd greater than 1 then never able to get gcd as 1
        elif ones > 0: return n - ones      ## num == 1 no need to convert into GCD to 1

        minLen = n
        ## Case-3: no 1's but GCD = 1
        for i in range(n):
            g = 0
            for j in range(i,n):
                g = gcd(g, nums[j])
                if g == 1:
                    minLen = min(minLen, j - i + 1)
                    break

        return (minLen - 1) + (n - 1)
