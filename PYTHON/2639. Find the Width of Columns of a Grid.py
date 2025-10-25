class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        m = len(grid[0])
        ans = []

        for j in range(m):
            maxiWidth = 0
            for i in range(n):
                num = grid[i][j]
                if num == 0:
                    width = 1
                else:
                    width = 1 if num < 0 else 0
                    num = abs(num)
                    while num:
                        num //= 10
                        width += 1
                maxiWidth = max(width, maxiWidth)
            ans.append(maxiWidth)

        return ans



class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        m = len(grid[0])
        ans = []

        for j in range(m):
            maxiWidth = 0
            for i in range(n):
                num = str(grid[i][j])
                width = len(num)
                maxiWidth = max(width, maxiWidth)
            ans.append(maxiWidth)

        return ans

