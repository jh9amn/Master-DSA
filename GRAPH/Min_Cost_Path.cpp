//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
	int isValid(int i, int j, int n, int m){
	    return i >= 0 && i < n && j >= 0 && j < m;
	}
	
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        
        // min heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> dp(n, vector<int> (m, INT_MAX));
        
        dp[0][0] = grid[0][0];
        
        pq.push({grid[0][0],{ 0, 0}});
        
        while(!pq.empty()){
            auto temp =  pq.top();
            pq.pop();
            
            int val = temp.first;
            int curr_i = temp.second.first;
            int curr_j = temp.second.second;
            
            for(int i=0; i<4; i++){
                int new_i = curr_i + dx[i];
                int new_j = curr_j + dy[i];
                
                if(isValid(new_i, new_j, n, m)){
                    int newVal = val + grid[new_i][new_j];
                    
                    if(newVal < dp[new_i][new_j]){
                        dp[new_i][new_j] = newVal;
                        pq.push({newVal,{new_i, new_j}});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends