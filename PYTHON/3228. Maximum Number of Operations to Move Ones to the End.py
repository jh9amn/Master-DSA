class Solution:
    def maxOperations(self, s: str) -> int:
        one_cnt = 0
        opt = 0
        n = len(s)
        i = 0

        while i < n:
            if s[i] == '1':
                one_cnt += 1
                i += 1
            else:
                opt += one_cnt
                while i < n and s[i] == '0':
                    i += 1
        return opt
