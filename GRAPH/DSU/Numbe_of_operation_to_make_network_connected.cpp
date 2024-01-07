#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int find_parent(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_parent(parent[x]);
    }
    
    void Union(int x, int y){
        x = parent[x];
        y = parent[y];
        
        if(x == y) return;
        if(size[x] > size[y]){
            parent[y] = x;
            size[x]++;
        }
        else{
            parent[x] = y;
            size[y]++;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU d(n);
        int extra_edge = 0;
        for(auto it : connections){
            if(d.find_parent(it[0]) == d.find_parent(it[1])) {
                extra_edge++;
                continue;
            }
            d.Union(it[0],it[1]);
        }
        
        int compo = 0;
        for(int i=0; i<n; i++){
            if(d.parent[i] == i) compo++;
        }
        if(extra_edge >= compo-1) return compo-1;
        return -1;    
    }
};
int main(){

}