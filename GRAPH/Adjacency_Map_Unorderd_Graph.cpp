#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<bits/stdc++.h>
using namespace std;

vector<unordered_set<int,int> > graph;
int v; // no of vertices

void add_edge(int src, int dest,int wt, bool bi_dir = true){ 
    graph[src].insert(dest);
    if(bi_dir){
        graph[dest].insert(src);
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for (auto& ele : graph[i]){
            cout<<ele<<",";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    graph.resize(v,unordered_set<int,int> ());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
      display();
      return 0;
}

/*
INPUT
7
7
0 2
0 1
1 5
2 5
2 3
3 6
6 4
0 -> 2 ,1 ,
1 -> 0 ,5 ,
2 -> 0 ,5 ,3 ,
3 -> 2 ,6 ,
4 -> 6 ,
5 -> 1 ,2 ,
6 -> 3 ,4 ,
7 ->
8 */
