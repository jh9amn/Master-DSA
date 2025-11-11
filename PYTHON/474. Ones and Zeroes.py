class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        ################## Memoization ############################
        
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




        ################# Tabulation ###############################


        dp = defaultdict(int)
        for i in range(len(strs)):
            mCnt = strs[i].count("0")
            nCnt = strs[i].count("1")

            for _m in range(m+1):
                for _n in range(n+1):
                    maxi = 0
                    if mCnt <= _m and nCnt <= _n:
                        maxi = max(dp[(i-1, _m, _n)],
                                        1 + dp[(i-1, _m - mCnt, _n - nCnt)])
                    else:
                        maxi = dp[(i-1, _m, _n)]

                    dp[(i, _m, _n)] = maxi
            
        return dp[(len(strs) - 1, m, n)]


