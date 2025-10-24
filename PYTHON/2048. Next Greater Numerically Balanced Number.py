class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        ## TC = O(K * D)    SC = O(D)
        while True:
            n += 1
            temp = n
            freq = defaultdict(int)
            while(temp):
                r = temp%10
                temp = temp//10
                freq[r] += 1
            
            valid = True
            for key, value in freq.items():
                if value != key:
                    valid = False
                    break

            if valid == True:
                return n
        return n

        
