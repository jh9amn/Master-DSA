class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort() 
        ans = set()
        for i in range(n):
            for j in range(i+1, n-1):
                st = set()
                sum2 = nums[i] + nums[j]
                for k in range(j+2, n):
                    need = target - (sum2 + nums[k])
                    if need in st:
                        quad = tuple(sorted([nums[i], nums[j], nums[k], need]))
                        ans.add(quad)
                    st.add(nums[k])     
        return [list(x) for x in ans] 
