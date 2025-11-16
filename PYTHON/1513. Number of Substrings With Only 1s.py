class Solution:
    def numSub(self, s: str) -> int:
     mod = 1e9 + 7
     ans  = 0
     canti = 0
     for i in range(len(s)):
        if s[i] == '0':
            canti = 0
        else: 
            canti += 1
            ans += (canti - 1) + 1
        ans = int(ans % mod)
     return ans
     
