
## https://www.interviewbit.com/problems/3-sum/

class Solution:
	# @param A : list of integers
	# @param B : integer
	# @return an integer
 
 
 # Binary search
    def binarySearch(self, left, right, target, B, nums):
        moreClose = float("inf")
        ans = None
        
        while(left <= right) :
            mid = left + (right - left) // 2
            newTarget = target + nums[mid]
            
            if(abs(B - newTarget) < moreClose):
                moreClose = abs(B - newTarget)
                ans = newTarget
            
            if(newTarget < B):
                left = mid + 1
            
            else: 
                right = mid - 1
            
        return ans
        
        
    
	def threeSumClosest(self, nums, B):
        n = len(nums)
        nums.sort()
        ans = None
        closeDiff = float("inf")
        
        for i in range(n-2):
            for j in range(i+1, n-1):
                curr_sum = self.binarySearch(j+1, n-1, nums[i] + nums[j], B, nums)
                
                if(curr_sum is not None and abs(B - curr_sum) < closeDiff) :
                    closeDiff = abs(B - curr_sum)
                    ans = curr_sum
                 
        return ans
        
        
        
    # Two Pointers
	def threeSumClosest(self, nums, B):
        n = len(nums)
        nums.sort()
        closeSum = nums[0] + nums[1] + nums[2]
        
        for i in range(n-2):
            left = i+1     
            right = n-1
            
            while(left < right):
                curr_sum = nums[i] + nums[left] + nums[right]
                if(abs(B - curr_sum) < abs(B - closeSum)):
                    closeSum = curr_sum
                
                if(curr_sum < B):
                    left += 1
                elif(curr_sum > B):
                    right -= 1
                else:
                    return curr_sum      
        return closeSum
