#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    typedef pair<int, double> pr;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            adj[a].push_back({b,prob});
            adj[b].push_back({a,prob});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});     // {prob , start} 

        vector<double> res(n,0.0);
        res[start] = 1.0;

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto it : adj[currNode]){
                int adjNode = it.first;
                double adjProb = it.second;
                cout<<adjNode<<" - > "<<adjProb;
                if(res[adjNode] < currProb * adjProb){
                    res[adjNode] = currProb * adjProb;
                    pq.push({res[adjNode], adjNode});
                }
            }
        }
        return res[end];
        
    }
};