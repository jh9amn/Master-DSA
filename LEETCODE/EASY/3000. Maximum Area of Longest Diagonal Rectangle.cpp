#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxi = 0;
        int ans = 0;
        for(auto it : dimensions) {
            int len = it[0];
            int wid = it[1];
            double diagonal = sqrt((len * len) + (wid * wid));
            int area = len * wid;
            if (diagonal > maxi) {
                maxi = diagonal;
                ans = area;
            } else if (diagonal == maxi) {
                ans = max(ans, area);
            }
        }
        return ans;
    }
};