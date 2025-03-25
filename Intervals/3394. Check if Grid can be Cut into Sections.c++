#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        /*
        * Scan endpoints left to right
        * And down to top
        * Similar to non- overlaping intervals
        * Specifically 3 Regions 
        * Maybe ignore that and focus on overlapping
        * We just need atleat 3 non overlaping intervals
        */

        vector<vector<int>> x, y;
        for(auto it : rectangles) {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }

        sort(begin(x), end(x));
        sort(begin(y), end(y));

        auto count_non_overlaping = [](vector<vector<int>> &intervals) {
            int count = 0;
            int prev_end = -1;

            for(auto it : intervals){
                if(prev_end <= it[0]) {         // prev_end <= curr_start
                    count++;
                }
                prev_end = max(prev_end, it[1]);        // update prev_end = max(prev_end, curr_end)
            }

            return count;
        };

        // if any coordinate have more than 3 intervals(rectangles) return true
        int ans = max(count_non_overlaping(x), count_non_overlaping(y));

        return ans >= 3;    
    }       
};