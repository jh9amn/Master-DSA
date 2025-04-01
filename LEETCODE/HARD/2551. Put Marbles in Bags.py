class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:

        # here two things are in miximum and miniscore that the first element and the last element
        # 1 3 5 1 
        # minimum => 1 + 1 + 3 + 1 -> 6
        # miximum => 1 + 3 + 5 + 1 -> 10      ans = 10 - 6 = 4
        # 0th idx 1 and 4th idx 1 => these element always common either in minimum or maximum it

        # Approach : break it into all splits
        # 1st spilt = 1+1    3+1 => 6       (minimum)
        # 2nd split = 1+3    5+1 => 10      (maximum)
        # 3rd split = 1+5    1+1 => 8
        
        # Note: both minimum and maximum split has first ele and last ele
        # and at the end return difference so they cancle out..

        # 1st split = 1+3 => 4
        # 2nd split = 3+5 => 8
        # 3rd split = 5+1 => 6

        # sort splits => [4 6 8]
        # ans = 8 - 4 = 4

        if k == 1:
            return 0
        n = len(weights)
        splits = [0] * (n - 1)
        for i in range(n-1) :
            splits[i] = weights[i] + weights[i+1]
        
        ans = 0
        splits.sort()

        i = k-1
        maxi = weights[0] + weights[-1] + sum(splits[-i:])
        mini = weights[0] + weights[-1] + sum(splits[:i])

        return maxi - mini

        # for i in range(k-1):
        #     ans = ans - splits[i]
        #     ans = ans + splits[n - i - 2]

        # return ans
