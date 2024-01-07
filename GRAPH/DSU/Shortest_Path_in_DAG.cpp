// firstly craeting a Directed Acyclic Graph (DAG) with weight too 
// and from source node 1 finding the SHORTEST distance from every node....
#include<bits/stdc++.h>
using namespace std;
class Graph{
  public:
  // DAG with weight
  unordered_map<int, list<pair<int,int>>> adj;
  void add_edge(int u,int v, int wt){
    pair<int,int> p = make_pair(v,wt);
    adj[u].push_back(p); 
  }

  void print_adj(){
    for(int i=0; i<adj.size(); i++){
        cout<<i<<"->";
        for(auto x : adj[i]){
            cout<<"("<<x.first<<","<<x.second<<")";
        }cout<<endl;
    }
  }

 // topological DFS 
  void topo_dfs(int i,vector<int> &vis,stack<int> &st){
    vis[i] = 1;
    for(auto it : adj[i]){
        if(!vis[it.first]){
            topo_dfs(it.first,vis,st);
        }
    }
    st.push(i);
  }

};

int main(){
    Graph g;
    g.add_edge(0,1,5);
    g.add_edge(0,2,3);
    g.add_edge(1,2,2);
    g.add_edge(1,3,6);
    g.add_edge(2,3,7);
    g.add_edge(2,4,4);
    g.add_edge(2,5,2);
    g.add_edge(3,4,-1);
    g.add_edge(4,5,2);

    g.print_adj();

    int n = 6; // total no node

    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            g.topo_dfs(i,vis,st);
        }
    }
    
    vector<int> topo(n);

    vector<int> dis(n,1e9); 
    int src = 1;
    dis[src] = 0;

    while(!st.empty()){
        int top = st.top();
        topo.push_back(top);
        st.pop();
        
        // here, find the shortest distance from source..
        /* poping stack ekement everytime and if dis[st.top] != 1e9
           then checking the adjNode of adj[st.top] 
           if(dis[st.top] and weight of adjNode is less than dis[adjNode])
           then put the val at dis[adjNode] = dis[st.top] + weight of adjNode 
        */

        if(dis[top] != 1e9){
            for(auto it : g.adj[top]){
                if(dis[top] + it.second  < dis[it.first]){
                    dis[it.first] = dis[top] + it.second;
                }
            }
        }
    }
    
    cout<<"Topological Sort"<<endl;
    for(int i=0; i<n; i++) cout<<topo[i]<<" ";
    cout<<endl;
    cout<<"Shortest Distance "<<endl;
    for(int i=0; i<n; i++) cout<<dis[i]<<" ";

    return 0;
}

// T.C = O(N+E)
// S.C = O(N+E)