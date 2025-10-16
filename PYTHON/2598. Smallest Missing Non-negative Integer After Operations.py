class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        freq = {}
        for num in nums:
            rem = num % value
            freq[rem] = freq.get(rem, 0) + 1

        start = 0
        while True:
            rem = start % value
            if freq.get(rem,0) == 0:
                return start
            freq[rem] -= 1
            start += 1
            
        return -1

