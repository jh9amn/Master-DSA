#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int n, m;
    bool isValid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        // min heap..
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0,0}});
        vis[0][0] = 1;

        vector<int> ans(queries.size(), 0);

        vector<pair<int, int>> qq;
        for(int i=0; i<queries.size(); i++){
            qq.push_back({queries[i], i});
        }

        sort(begin(qq), end(qq));

        vector<vector<int>> dir = {{0,-1}, {0, 1}, {1, 0}, {-1, 0}};

        int points = 0;

        for(auto it : qq) {
            while(!pq.empty() && pq.top().first < it.first) {
                int val = pq.top().first;
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                pq.pop();

                points++;

                for(auto k : dir) {
                    int newi = k[0] + i;
                    int newj = k[1] + j;

                    if(isValid(newi, newj) && vis[newi][newj] == 0) {
                        vis[newi][newj] = 1;
                        pq.push({grid[newi][newj], {newi, newj}});
                    }
                }
            }
            ans[it.second] = points;
        }
        return ans;
    }
};