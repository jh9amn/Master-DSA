//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int n = mat.size();
        vector<int> ans;
        int row = 0;
        int col = 0;
        while(ans.size() < n*n){
            
            // Updoward Diagonal till my first row and last col not reached
            while(row >= 0 and col < n){
                if(row >= 0 && col < n && col >= 0 && row < n ){
                    ans.push_back(mat[row][col]);
                    mat[row][col] = 1000;
                }
                row--;
                col++;
            }
            
            if(ans.size() == n*n) break;
            
            row = max(0,row);
            col = min(n-1,col);
            
            while(mat[row][col]==1000){
                row++;
            }
            
            
            // downward digonal till my last row and first col not reached
            while(col >= 0 && row < n){
                if(row >= 0 && col < n && col >= 0 && row < n ){
                    ans.push_back(mat[row][col]);
                    mat[row][col] = 1000;
                }
                
                row++;
                col--;
            }
            
            if(ans.size() == n*n) break;
            
            
            row = min(row,n-1);
            col = max(col,0);
            
            while(mat[row][col]==1000){
                col++;
            }
           
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends