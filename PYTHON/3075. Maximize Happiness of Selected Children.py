class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        max_heap = []
        ## Push ele in neg
        max_heap = [-h for h in happiness]
        ## maxi heap creation
        heapq.heapify(max_heap)

        cnt = 0
        ans = 0
        for _ in range(k):
            if not max_heap:
                break

            val = -heapq.heappop(max_heap)
            val -= cnt
            if val <= 0:
                break
            ans += val
            cnt += 1

        return ans

