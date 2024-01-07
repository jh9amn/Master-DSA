//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool isValid(int row,int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    
    int dir[4][2] ={      {-1,0},
                {0,-1},             {0,1},
                          {1,0}
    };
    
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
    
        int n = heights.size();
        int m = heights[0].size();
        
        // int pathDiff[n][m] = {1e9};
        vector<vector<int>> pathDiff(n,vector<int>(m,1e9));
        pathDiff[0][0] = 0;
        

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == m-1) return diff;
            
            for(auto x : dir){
                int newRow = row + x[0];
                int newCol = col + x[1];
            
                if( isValid(newRow,newCol,n,m) ){
                    int newEffort = max ( abs(heights[row][col] - heights[newRow][newCol]), diff);
                    if(newEffort < pathDiff[newRow][newCol]) {
                      pathDiff[newRow][newCol] = newEffort;
                      pq.push({newEffort,{newRow,newCol}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends