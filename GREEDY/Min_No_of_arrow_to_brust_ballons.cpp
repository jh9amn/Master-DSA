#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());   //sort with start time
        int end_time = intervals[0][1];
        int ans = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= end_time){   // prev end time > next start time the ans++
                ans++;
                end_time = min(end_time, intervals[i][1]);
            }
            else end_time = intervals[i][1];
        }
        return  intervals.size() - ans;
        
    }
};




int main(){


}