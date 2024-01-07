#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
vector<list<int>> graph;

void add_edge(int u, int v, bool biDir = true){
    graph[u].push_back(v);
    if(biDir){
        graph[v].push_back(u);
    }
}



void topological_BFS(){

    // kahn's algo
    vector<int> inDegree(n,0);
    for(int i=0; i<n; i++){
        for(auto neighbour : graph[i]){
            inDegree[neighbour]++;
        } 
    }

    vector<int> vis(n,0);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0) q.push(i);
        vis[i]++;
    }


    while(!q.empty()){
        int node = q.front();
        cout<<"sorting :"<< node<<" ";
        q.pop();
        for(auto it : graph[node]){
            if(vis[it] > 0){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                    vis[it]--;
                }
            }
        }
    }
}


int main(){
    cout<<"Enter the graph Size ";
    cin>>n;
    graph.resize(n, list<int>());
    int e;
    cout<<"Enter the number of edge of Graph ";
    cin>>e;
    while(e--){
        int u,v;
        cout<<"Enter the element from which the has connection ";
        cin>>u>>v;
        add_edge(u,v,false);
    }

    topological_BFS();
    return 0;
}