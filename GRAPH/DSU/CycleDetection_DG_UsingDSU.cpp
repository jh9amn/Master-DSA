#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x){
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}
 
bool Union(vector<int> &parent,vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return true;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
    return false;
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
            int x,y;
            cin>>x>>y;
            if(Union(parent,rank,x,y) == true)  cout<<"Cycle Detected";
    }
    cout<<"Cycle not Detected";
}

/*
INPUT....
Enter the size of parent: 10
Enter the no of queries: 10
0 1
0 2
0 3
3 4
4 5
5 6
3 6
Cycle Detected
*/