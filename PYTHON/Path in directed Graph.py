from collections import deque

class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B):
        graph = [[] for _ in range(A + 1)]
        
        for u, v in B:
            graph[u].append(v)

            
        vis = [False] * (A + 1)
        vis[1] = True
        q = deque([1])
        while q:
            node = q.popleft()
            if node == A:
                return 1
                
            for nei in graph[node]:
                if vis[nei] == False:
                    vis[nei] = True
                    q.append(nei)
                    
        return 0
                    



## DFS

import sys
sys.setrecursionlimit(10**7)

class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B):
        graph = [[] for _ in range(A+1)]
        
        for u, v in B:
            graph[u].append(v)
        
        vis = [False] * (A+1)
        vis[1] = True
        
        def dfs(node):
            if node == A:
                return True
            for nei in graph[node]:
                if vis[nei] == False:
                    vis[nei] = True
                    if dfs(nei):
                        return True
            return False
            
        return 1 if dfs(1) else 0
        
            

            
