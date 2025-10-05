class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n = len(heights)
        m = len(heights[0])


        dir = [(0,1), (0,-1), (-1,0), (1,0)]

        def bfs(que):
            vis = [[False] * m for _ in range(n)]
            q = deque(que)

            while q:
                r, c = q.popleft()
                vis[r][c] = True

                for it in dir:
                    nr = r + it[0]
                    nc = c + it[1]

                    if (nr >= 0 and nr < n and nc >= 0 and nc < m and not vis[nr][nc] and
                        heights[r][c] <= heights[nr][nc]):
                        q.append([nr, nc])

            return vis

        pacific = [(i, 0) for i in range(n)] + [(0, j) for j in range(m)]
        atlantic = [(i, m-1) for i in range(n)] + [(n-1, j) for j in range(m)]

        pacificReach = bfs(pacific)
        atlanticReach = bfs(atlantic)

        ans = []

        for i in range(n):
            for j in range(m):
                if pacificReach[i][j] and atlanticReach[i][j]:
                    ans.append([i, j])
        
        return ans
