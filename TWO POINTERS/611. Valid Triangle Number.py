# Brute Force
# TC = O(n^3)
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        for i in range(0, n-2):
            for j in range(i+1, n-1):
                for k in range(j+1, n):
                    if (nums[i] + nums[j] > nums[k] and 
                       nums[i] + nums[k] > nums[j] and
                       nums[j] + nums[k] > nums[i]):
                       count += 1

        return count



# Using Binary Search
# T.C = O(n^2 * log(n))
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)

        if n < 3:
            return 0

        nums.sort()
        for i in range(0, n-2):
            for j in range(i+1, n-1):
                ## Binary Search
                target = nums[i] + nums[j]
                left = j+1
                right = n-1
                k = j
                while left <= right:
                    mid = (left + right) // 2
                    ## I can  get more valid combination
                    if nums[mid] < target:
                        left = mid+1
                        k = mid
                    else:
                        right = mid-1
                if k > j :
                    count += (k-j)

        return count



# More Intutive and optimal approach using Two Pointer
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)

        if n < 3:
            return 0

        nums.sort()
        k = n-1

        ## T.C = O(n^2)
        while k > 1:
            i = 0
            j = k-1
            while(i < j):
                if(nums[i] + nums[j] > nums[k]):
                    count += (j - i)
                    j -= 1
                else:
                    i += 1
            k -= 1
        
        return count