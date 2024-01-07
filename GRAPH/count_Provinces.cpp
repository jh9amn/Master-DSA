#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        // Simple BFS call
        void bfs(int start, vector<int> list[], vector<bool> &vis){
            queue<int> q;
            q.push(start);
            vis[start] = true;
            while(!q.empty()){
                start = q.front();
                q.pop();
                for(auto it : list[start]){
                    if(vis[it] == false){
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }



        // simple DFS solution
        void dfs(int start, vector<int> list[], vector<bool> &vis){
            vis[start] = true;
            for(auto it : list[start]){
                if(vis[it] != true)
                    dfs(it,list,vis);
            }
        }

        int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // converting adjacency matrix into adjacency list
        vector<int> list[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j) {   // i != j means not self node allow
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        // passing BFS for no of connected componenet
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                count++;
                dfs(i,list,vis);
            } 
        }
        return count;  
    }
};
int main(){

}