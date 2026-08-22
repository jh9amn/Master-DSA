#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // maximum group seats can assign
        int max4Seatassigned = n << 1; // (2*n)
        unordered_map<int, vector<bool>> reserved;

        for(auto it: reservedSeats) {
            int row = it[0];
            int seat = it[1];

            if(reserved.find(row) == reserved.end())
                reserved[row] = vector<bool>(3, false);

            if(seat >= 2 and seat <= 5) reserved[row][0] = true;
            if(seat >= 4 and seat <= 7) reserved[row][1] = true;
            if(seat >= 6 and seat <= 9) reserved[row][2] = true;
        }

        for(auto it : reserved){
            bool l = it.second[0];
            bool m = it.second[1];
            bool r = it.second[2];

            // All three possible groups are blocked
            if(l and m and r) max4Seatassigned -= 2;

            // At least one of the three possible groups is blocked
            // But there is still at least one possible family placement
            else if (l or m or r) max4Seatassigned -= 1;
        }
        return max4Seatassigned;
    }
};