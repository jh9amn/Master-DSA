class Solution:
	# @param A : list of integers
	# @param B : integer
	# @return a list of list of integers
	def combinationSum(self, A, B):
            A = sorted(list(set(A)))
            n = len(A)
            ans = []
            
            def solve(i, target, path):
                if target == 0:
                    ans.append(path.copy())
                    return
                    
                if i == n or target < 0:
                    return 
                    
                ## Backtrack
                path.append(A[i])
                solve(i, target - A[i], path)
                path.pop()
                solve(i+1, target, path)
                
                    
            solve(0, B, [])
            return ansCombination Sum
