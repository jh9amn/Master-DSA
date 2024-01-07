#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x){
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}
 
void Union(vector<int> &parent,vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}


int main(){
    int n,m;
    cout<<"Enter the size of parent: ";
    cin>>n;
    cout<<"Enter the no of queries: ";
    cin>>m;
    vector<int> parent(n+1), rank(n+1,0);
    for(int i=0; i<=n; i++) parent[i] = i;

    while(m--){
        cout<<"Enter u for union or f for find: ";
        string str;
        cin>>str;
        if(str == "u"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        }else{
            int x;
            cin>>x;
            cout<<find(parent,x)<<"\n";
        }
    }
}