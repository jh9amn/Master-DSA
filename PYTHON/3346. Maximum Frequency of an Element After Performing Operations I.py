"""
nums = [1, 7, 13, 13, 17]   k = 5  numOp = 2
 
k range = -5 -> 5
-> 13, 13 + 0, 17 - 4 
-> 13, 13, 13

Observation: It is better to always pick the num which is present in my array

"""

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        ## find the cumelative freq of the nums
        maxEle = max(nums)
        n = len(nums)
        cumFreq = [0] * (maxEle + k + 1)

        ans = 0

        ## calculating freq
        for num in nums:
            cumFreq[num] +=  1

        ## now calculating cumelative frequency
        for i in range(1, maxEle+k+1):
            cumFreq[i] = cumFreq[i-1] + cumFreq[i]

        ## let pick target which is present into nums
        for target in range(maxEle+1):
            ## target is not of nums
            if(cumFreq[target] == 0):
                continue
            
            l = max(0, target - k)
            r = min(target + k, maxEle)


            ## find the Freq range of target
            totalCnt = cumFreq[r] - (cumFreq[l-1] if l > 0 else 0)
            ## Freq of target
            targetCnt = cumFreq[target] - (cumFreq[target-1] if target > 0 else 0)

            needConversion = totalCnt - targetCnt

            maxPossibleConversion  = min(numOperations, needConversion)

            ans = max(ans, targetCnt + maxPossibleConversion)

        return ans

            

        
            

