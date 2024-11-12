#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    void findCurrMaxBeauty(vector<vector<int>>& items, int query, int &currMaxi){
        int i=0; int j = items.size()-1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(items[mid][0] <= query) {
                currMaxi = items[mid][1];
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> ans;

        int maxi = INT_MIN;
        for(auto &it : items){
            if(it[1] > maxi){
                maxi = it[1];
            }
            else {
                it[1] = maxi;
            }
        }

        for(auto it : queries){
            int currMaxi = INT_MIN;
            findCurrMaxBeauty(items, it, currMaxi);
            if(currMaxi == INT_MIN){
                currMaxi = 0;
            }
            ans.push_back(currMaxi);
        }
        return ans;
    }
};