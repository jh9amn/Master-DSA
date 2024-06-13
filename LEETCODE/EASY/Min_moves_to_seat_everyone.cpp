#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans = 0;
        int n = seats.size();
        
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        
        for(int i=0; i<n; i++){
            ans += abs(seats[i] - students[i]);
        }
        
        return ans;
    }
};

int main(){}