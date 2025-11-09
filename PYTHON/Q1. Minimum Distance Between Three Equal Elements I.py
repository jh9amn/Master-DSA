class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        mp = defaultdict(list)

        for i,num in enumerate(nums):
            mp[num].append(i)

        ans = float('inf')
        for it in mp.values():
            if len(it) >= 3:
                for i in range(len(it)-2):
                    a, b, c = it[i], it[i+1], it[i+2]
                    ans = min(ans, (b-a) + (c-b) + (c-a));

        return ans if ans != float('inf') else -1 
                
