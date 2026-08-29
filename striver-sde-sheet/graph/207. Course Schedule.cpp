using vi = vector<int>;
class Solution {
public:
    /*
    Basically its graph problem,
    Detect Cycle in Directed Graph
    so we can use topo sort to detect cycle in DAG
    if there is no cycle means no prerequisites courses dependent on each other
    */

    bool dfs(int start, vi &vis, vi &pathVis, unordered_map<int, vi> &adj) {
        vis[start] = 1;
        pathVis[start] = 1;
        
        for(auto it: adj[start]) {
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adj)) return true;
            }
            // if the node is previously visited
            // and it has be visited on same path..
            // then cycle
            else if(pathVis[it] == 1) {
                return true;
            }
        }
        pathVis[start] = 0; 
        return false;
    }


    bool canFinish(int nc, vector<vector<int>>& p) {
        unordered_map<int, vi> adj;

        // created adjecency list
        for(auto &it: p){
            adj[it[0]].push_back(it[1]);
        }

        // if vis 
        // 0 -> not visited yet
        // 1 -> in the current path
        // 2 -> all visited from another routh
        vi vis(nc,0);
        vi pathVis(nc,0);

        for(int i=0; i<nc; i++){
            if(!vis[i]) {
                // Cycle found -> cannot finish
                if(dfs(i, vis, pathVis, adj)) return false;
            }
        }

        // No cycles -> can finish
        return true;
    }
};
