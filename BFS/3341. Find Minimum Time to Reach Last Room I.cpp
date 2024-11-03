#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};
        vector<vector<int>> vis(n, vector<int> (m,0));
        
         // Priority queue to always expand the minimum time room
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});  // {current_time, row, col}
        
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;
        
        while(!pq.empty()){
            auto [currTime, i, j] = pq.top();
            pq.pop();

            if(i == n-1 and j == m-1) return currTime;
    
            for(auto d : dir){
                int newI = i + d[0];
                int newJ = j + d[1];                
                if(newI >= 0 and newI < n and newJ >= 0 and newJ < m){
                    int waitTime = max(moveTime[newI][newJ] - currTime, 0);
                    int newTime = currTime + 1 + waitTime;
                    
                    if (newTime < minTime[newI][newJ]) {
                        minTime[newI][newJ] = newTime;
                        pq.push({newTime, newI, newJ});
                    }
                    
                }
            }
        }
        return minTime[n-1][m-1];
    }
};