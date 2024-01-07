#include<bits/stdc++.h>
using namespace std;

int find(int ele, vector<int> &parent){
    return parent[ele] = (parent[ele] == ele) ? ele : find(parent[ele], parent);
}

void Union(int a,int b, vector<int> &parent, vector<int> & size, vector<int> &rank, vector<int> &minimal, vector<int> &maximal){
    a = find(a,parent);
    b = find(b,parent);
    if(a == b ) return;  // if both have same parent dont need to change....
    if(rank[a] > rank[b]){
        rank[a]++;
        parent[b] = a;
        size[a] += size[b];
        minimal[a] = min(minimal[b], minimal[a]);
        maximal[a] = max(maximal[a], maximal[b]);
    }
    else{
        rank[b]++;
        parent[a] = b;
        size[b] += size[a];
        minimal[b] = min(minimal[a], minimal[b]);
        maximal[b] = max(maximal[a], maximal[b]);
    }
}

// void file_i_o(){

// }
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    vector<int> rank(n+1,0);
    for(int i=0; i<=n; i++){
        parent[i] = i;
        minimal[i] = i;
        maximal[i] = i;
    }

    while(m--){
        string s;
        cin>>s;
        if(s == "union"){
            int x,y;
            cin>>x>>y;
            Union(x,y,parent,size,rank,minimal,maximal);
        }
        else{
            int ele;
            cin>> ele;
            ele = find(ele,parent);
            cout<<minimal[ele]<<" "<<maximal[ele]<<" "<<size[ele]<<"\n";
        }
    }
}