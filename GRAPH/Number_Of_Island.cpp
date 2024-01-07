  // https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
   
   #include<bits/stdc++.h>
   using namespace std; 
    
    void bfs(vector<vector<char>> &grid, int i, int j,vector<vector<bool>> &vis){
        vis[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // for traversing in all the eight direction of the grid
            for(int deltarow = -1; deltarow <= 1; deltarow++){
                for(int deltacol = -1; deltacol <= 1; deltacol++){
                    int newrow = row + deltarow;
                    int newcol = col + deltacol;
                    // newrow and newcol not go out of bound and 
                    if((newrow >= 0 && newrow < n) && (newcol >=0 && newcol < m) &&
                    grid[newrow][newcol] == '1' && vis[newrow][newcol] == false ){

                        vis[newrow][newcol] = true;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
    }

     int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == false ){
                    count++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }

    int main(){

    }