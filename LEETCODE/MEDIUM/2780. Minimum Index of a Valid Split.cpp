#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x = -1;
        int maxFreq = 0;
        int n= nums.size();

        unordered_map<int, int> mp;

        for(auto it : nums) {
            mp[it]++;


            // store maxFreq ele and it value
            if(mp[it] > maxFreq) {
                maxFreq = mp[it];
                x = it;
            }
        }

        int maxCurrFreq = 0;
        for(int i=1; i<=n-1; i++){
            if(nums[i-1] == x) {
                maxCurrFreq++;

                // the first test case as:
                // i == 3:
                // 2 * 2 > 3 && (3 - 2) * 2 > (4 - 3) return 3-1;
                if(maxCurrFreq * 2 > i && (maxFreq - maxCurrFreq) * 2  > (n - i)){
                    return i-1;
                }
            }
        }
        return -1;
    }
};