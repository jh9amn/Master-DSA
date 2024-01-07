#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){ 
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        // for(int j=0; j<=graph[i].size(); j++){
        //     cout<<graph[i][j];
        for(auto ele : graph[i]){
            cout<<ele<<" ,";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
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
