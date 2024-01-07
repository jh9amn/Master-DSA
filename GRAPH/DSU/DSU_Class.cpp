#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent, rank, size;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int find_ulti_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_ulti_parent(parent[node]);
    }

    void unionByRank(int u, int v){
        u = find_ulti_parent(u);
        v = find_ulti_parent(v);
        if( u == v) return;
        if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else if(rank[v] > rank[u])  {
            parent[u] = v;
        }
        else {  // if(have same rank) then both parent become one..
            parent[u] = v;
            rank[u]++;
        }
    }

        void unionBySize(int u, int v){
        u = find_ulti_parent(u);
        v = find_ulti_parent(v);
        if( u == v) return;
        if(size[v] > size[u])  {
            parent[u] = v;
            size[v] += size[u];
        }
        else {  // if(have same rank) then both parent become one..
            parent[u] = v;
            size[u] += size[v];
        }
    }
};


int main(){
    DSU ds(7);
    // UNION BY RANK..
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // if(ds.find_ulti_parent(3) == ds.find_ulti_parent(7)) {
    //     cout<<"Same\n";
    // }else{
    //     cout<<"Not Same\n";
    // }

    // ds.unionByRank(3,7);

    // if(ds.find_ulti_parent(3) == ds.find_ulti_parent(7)) {
    //     cout<<"Same\n";
    // }else{
    //     cout<<"Not Same\n";
    // }

    // UNION BY SIZE..
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.find_ulti_parent(3) == ds.find_ulti_parent(7)) {
        cout<<"Same\n";
    }else{
        cout<<"Not Same\n";
    }

    ds.unionBySize(3,7);

    if(ds.find_ulti_parent(3) == ds.find_ulti_parent(7)) {
        cout<<"Same\n";
    }else{
        cout<<"Not Same\n";
    }
    return 0;
}