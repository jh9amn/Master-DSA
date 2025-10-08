class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(potions)

        def binarySearch(num, l, r):
            while l <= r:
                mid = l + (r - l) // 2
                if(num * potions[mid] >= success and (mid == 0 or num * potions[mid-1] < success)):
                    return n - mid
                elif(num * potions[mid] < success) :
                    l = mid + 1
                else:
                    r = mid - 1
            return 0

        ans = []
        for it in spells:
            count = binarySearch(it, 0, n-1)
            ans.append(count)
        
        return ans
