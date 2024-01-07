//{ Driver Code Starts
//Initial template for C++

/*
Floyd Warshall algo is used to find shortest path from every Index/Node
firsly,It is applicable in Directedt Graph.. If graph is undirected convert them in directed form like
(1 --- 2) is written as (1 ---> 2) and (2 ----> 1) with same edge Weight. And then convert them into Adjecent Matrix
and all the ele in matrix[i][i] must Filled with ZERO..
After finding shortest path matrix  if(matrix[i][i] < 0) then there is negative Cycle..
*/

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	           if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	        }
	        matrix[i][i] = 0; 
	    }
	    
	    // Floyd Warshall Algorithm....
	    for(int vai = 0; vai < n; vai++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][vai] + matrix[vai][j]);
	            }
	        }
	    }
	    
	    // for finding Cycle..
	    // if(matrix[i][i] < 0) then Negative Cycle..
	    
	   for(int i=0; i<n; i++){
	       if(matrix[i][i] < 0) cout<<"There is a Negative Cycle";
	   }

	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends