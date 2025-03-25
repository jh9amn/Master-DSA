#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // set<int> occupied;
        // // Iterate over each meeting and mark the days occupied
        // for (auto &it : meetings) {
        //     for (int d = it[0]; d <= it[1]; d++) {
        //         occupied.insert(d);
        //     }
        // }
        
        // // The remaining free days will be total days - occupied days
        // return days - occupied.size();
        

        int n = meetings.size();
        sort(begin(meetings), end(meetings));

        int prev_end = 0;
        for(auto meeting : meetings) {
            int start = max(meeting[0], prev_end + 1);
            int end = meeting[1];
            int length = end - start + 1;
            days -= max(length, 0);
            prev_end = max(prev_end, end);
        }
        return days;
    }
};