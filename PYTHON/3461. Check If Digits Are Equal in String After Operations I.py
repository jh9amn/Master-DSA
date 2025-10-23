class Solution:
    def hasSameDigits(self, s: str) -> bool:
        s = list(s)
        while len(s) > 2:
            temp = ""
            for i in range(1, len(s)):
               temp += str((int(s[i]) + int(s[i-1])) % 10)
            s = temp
        if len(s) == 2 and s[0] == s[1]:
            return True
        else:
            return False

