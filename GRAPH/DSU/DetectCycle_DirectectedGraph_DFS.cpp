#include<bits/stdc++.h>
using namespace std;

// HERE WE ARE DETECTING CYCLE IN DIRECTED GRAPH USING DFS MATHOD 
// BUT WE USING TWO VISITED VECTOR (1) VIS , (2) PATHVIS 
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfsCheck(adjNode,adj,vis,pathVis) == true) return true;
            }
            else if(pathVis[adjNode] == 1) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        // for different Component
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis) == true) return true;
            }
        }
        return false;
    }


    // HERE DETECTING CYCLE IN DG USING DFS BY JUST ONLY USING ONE VISITED VECTOR..

    
int main(){

}