class Solution:
    def maxFreqSum(self, s: str) -> int:
        mp = Counter(s)
        vowel = {'a', 'e', 'i', 'o', 'u'}

        vmax = max((mp[c] for c in vowel if c in mp), default = 0)
        cmax = max((mp[c] for c in mp if c not in vowel), default = 0)
        
        return vmax + cmax


######################################################################################################3


class Solution(object):
    def maxFreqSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {}
        for c in s:
            if c in dict:
                dict[c] += 1
            else:
                dict[c] = 1
        
        vmax = 0
        cmax = 0
        
        for key,val in dict.items():
            if key == 'a' or key == 'e' or key == 'i' or key == 'u' or key == 'o':
                vmax = max(vmax, dict[key])
            else:
                cmax = max(cmax, dict[key])
        
        return cmax + vmax
