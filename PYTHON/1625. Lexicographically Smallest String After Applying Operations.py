class Solution:
    def add(self, s: str, a: int) -> str:
        s = list(s)
        for i in range(1,len(s), 2):
            s[i] = str((int(s[i]) + a) % 10)
        return ''.join(s)

    def rotate(self, s: str, b: int) -> str:
        b = b % len(s)
        # return s[-b:] + s[:-b]

        # Another way
        ## abcdef
        s = list(s)
        s = s[::-1]   # fedcba
        s[:b] = reversed(s[:b])    # efdcba
        s[b:] = reversed(s[b:])    # efabcd
        return "".join(s)
        
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        q = deque([s])
        seen = set([s])
        smallest = s

        while q:
            curr = q.popleft()
            smallest = min(smallest, curr)

            addstr = self.add(curr, a)
            if(addstr not in seen):
                seen.add(addstr)
                q.append(addstr)

            rotatestr = self.rotate(curr, b)
            if(rotatestr not in seen):
                seen.add(rotatestr)
                q.append(rotatestr)

        return smallest


"""
    s = "abcdef"
    s[-b:] + s[:-b]
    = "ef" + "abcd"
    = "efabcd"
"""
