#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        // Building Adjeceny List
        auto buildAdj = [&](vector<vector<int>> edges) -> unordered_map<int, vector<int>> {
            unordered_map<int, vector<int>> adj;

            for (auto& it : edges) {
                int u = it[0];
                int v = it[1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            return adj;
        };

               // this function will find farthest end node from any point and distance too...
        auto BFS = [&](unordered_map<int, vector<int>>& adj, int src) -> pair<int,int> {
            queue<int> q;
            q.push(src);

            int farthestNode = src;
            int maxDist = 0;

            unordered_set<int> st;
            st.insert(src);
            
            while(!q.empty()){
                int queSize = q.size();

                while(queSize--){
                    int currNode = q.front();
                    q.pop();

                    farthestNode = currNode;

                    for(auto it : adj[currNode]){
                        if(!st.count(it)) {
                            q.push(it);
                            st.insert(it);
                        }
                    }
                }
                if(!q.empty()) maxDist++;
            }
            return {farthestNode, maxDist};
        };

        // Finding Daimeter
        auto findDiameter = [&](unordered_map<int, vector<int>> adj) -> int {
            // find the farthest node from ramdom node 0
            pair<int, int> p1 = BFS(adj, 0);  
            int farthestNode = p1.first;
            int dist = p1.second;

            // this farthest node is the one end of the diameter
            // now, find the fathest node fro this one end of diameter(farthestNode)
            pair<int, int> p2 = BFS(adj, farthestNode);
            int otherEndOfFarthestNode = p2.first;
            int diameter = p2.second;

            return diameter;
        };

        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int D1 = findDiameter(adj1);
        int D2 = findDiameter(adj2);

        int radius1 = (D1 + 1) / 2;         // here taking seal value
        int radius2 = (D2 + 1) / 2;         // here taking seal value

        // Combine the two graphs by connecting any node from adj1 to adj2
        int combinedDiameter = radius1 + radius2 + 1;
        
        return max({D1, D2, combinedDiameter});
    }
};