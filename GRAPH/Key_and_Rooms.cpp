#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool room(vector<vector<int>>& rooms, vector<bool> &vis){
        queue<int> q;
        // unordered_set<int> s;
        q.push(0);
        // s.insert(0);
        vis[0] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neighbour : rooms[curr]){
                if(vis[neighbour] == 0){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
        }
        int count = 0;
        // if(vis.size() == rooms.size()) return true;
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == 1) count++;
        }
        if(count == rooms.size()) return true;
        return false;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        return room(rooms,vis);
        
    }
};
int main(){

}
 