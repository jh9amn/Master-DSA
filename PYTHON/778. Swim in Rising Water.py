import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        dir = [[1,0], [-1,0], [0,1], [0,-1]]
        n, m = len(grid), len(grid[0])

        minHeap = []
        vis = [[False] * m for _ in range(n)]

        ## MinHeap ##
        ## type = pair<int, pair<int, int>> 
        heapq.heappush(minHeap, (grid[0][0], (0, 0)))
        vis[0][0] = True

        while minHeap:
            t, (r, c) = heapq.heappop(minHeap)
            vis[r][c] = True

            if(r == n-1 and c == n-1):
                return t

            for it in dir:
                nr = it[0] + r
                nc = it[1] + c

                if(nr >= 0 and nr < n and nc >= 0 and nc < m and not vis[nr][nc]):
                    vis[nr][nc] = True
                    heapq.heappush(minHeap, (max(t, grid[nr][nc]), (nr,nc)))

        return -1

        
