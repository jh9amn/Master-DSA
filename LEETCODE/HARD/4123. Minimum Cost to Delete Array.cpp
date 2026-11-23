using ll = long long;

/*
2 -7 3 -5 -4 -6 7

## to delete array, must need to consider first and last elements
## to minimize max, need to take almost all neg elemens b/w [1,n-1]
## and the neg elements count should be even to make pair to delete
## if it is odd in number then
    - leave the most greatest neg eleement which is more near to zero
    - or pick one smallest positive number 

*/

class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        ll ans = nums[0] + nums[n-1];
        ll sum = 0;

        ll greatestNeg = LLONG_MIN;
        ll smallestPos = LLONG_MAX;
        int cnt = 0;


        for(int i=1; i <= n-2; i++){
            // neg ele then add
            if(nums[i] < 0){
                sum += nums[i];
                cnt++;
                greatestNeg = max(greatestNeg, ll(nums[i]));
            }
            else {
                smallestPos = min(smallestPos, ll(nums[i]));;
            }
        }

        if(cnt % 2 == 1) {
            sum = min(ll(sum - greatestNeg), ll(sum + smallestPos));
        }

        return ans + sum;

    }
};
