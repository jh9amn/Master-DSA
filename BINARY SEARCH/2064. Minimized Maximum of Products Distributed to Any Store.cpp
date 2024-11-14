#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    bool possibleDistribution(int mid, vector<int>& quantities, int shops){
        for(auto &it : quantities){
            int shopsUsed = it / mid;  // shops - ceil value 
            if(it % mid != 0) shopsUsed += 1;
            shops -= shopsUsed;

            // shops -= (it + mid - 1)/mid;

            if(shops < 0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {

        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());

        if(n == quantities.size()) return r;

        // Binary Search on answer..
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(possibleDistribution(mid, quantities, n)){
                ans = mid;
                r = mid - 1;
            }
            else { 
                l = mid + 1;
            }
        }
        return ans;
    }
};