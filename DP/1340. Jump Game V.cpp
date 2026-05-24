class Solution {
public:
    int N;
    unordered_map<int, int> dp;
    int solve(int i, int d, vector<int> &arr){

        int result = 1;

        if(dp.count(i)) {
            return dp[i];
        }

        // go left     (i-d) <-- i
        for(int j=i-1; j >= max(0, i-d); j--){
            if(arr[j] >= arr[i]) break;

            result = max(result, 1+solve(j, d, arr));
        }

        // go right     i --> (i+d)
        for(int j=i+1; j <= min(i+d,N-1); j++){
            if(arr[j] >= arr[i]) break;

            result = max(result, 1+solve(j, d, arr));
        }

        return dp[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        N =  n;
        dp.clear();
        int result = 0;
        for(int i=0; i<n; i++) {
            result = max(result, solve(i, d, arr));
        }

        return result;
    }
};
