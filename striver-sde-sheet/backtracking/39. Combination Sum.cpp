using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    void solve(vvi &ans, vi &temp, vi &candi, int target, int i) {

        if(i == candi.size()) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        // take that one
        if((target - candi[i]) >= 0) {
            temp.push_back(candi[i]);
            solve(ans, temp, candi, target - candi[i], i);
            temp.pop_back();
        }

        // skip and go ahead to next index
        solve(ans, temp, candi, target, i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vvi ans;
        vi temp;

        solve(ans, temp, candidates, target, 0);
        return ans;
    }
};
