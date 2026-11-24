using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        vector<int> conti(n, 1); 
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                conti[i] = conti[i-1] + 1;
            }
        }

        ll mini = LLONG_MAX;
        for(int i=n-1; i>=1; i--) {
            
            // contigious ele
            if(i < n-1 and nums[i] == nums[i+1]) {
                continue;
            }
            int s_idx = i;
            int p_idx = i - conti[i] + 1;

            // donot pick first and last element
            if(p_idx >= n-1 || s_idx <= 0) {
                continue;
            }

            ll prefix = 1LL * p_idx * nums[i];
            ll suffix = 1LL * (n-s_idx-1) * nums[i];

            mini = min(mini, ll(prefix + suffix));
        }

        return mini;
    }
};
