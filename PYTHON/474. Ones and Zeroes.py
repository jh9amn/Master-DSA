class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = {}

        def dfs(i, m, n):
            if i == len(strs):
                return 0
            
            if(i, m, n) in dp:
                return dp[(i, m, n)]

            mCnt = strs[i].count("0")
            nCnt = strs[i].count("1")

            maxi = dfs(i+1, m, n)

            if m >= mCnt and n >= nCnt:
                maxi = max(maxi, 1 + dfs(i+1, m - mCnt, n - nCnt))

            dp[(i, m, n)] = maxi
            return dp[(i, m, n)]

        return dfs(0, m, n)
