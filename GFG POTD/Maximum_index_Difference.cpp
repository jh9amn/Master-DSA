//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    int maxIndexDiff(int a[], int n) 
    { 
        
        // Brute Force (TLE)
        // if( n ==1 ) return 0;
        // int ans = -1;
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(a[j] > a[i] && j - i > ans) {
        //             ans = j - i;
        //         }
        //     }
        // }
        // return ans;
    
        
        
        int suffMax[n] = {INT_MIN};
        int suffMin[n] = {INT_MAX};
        int mini = a[0];
        int maxi = a[n-1];

        // prefix Min array
        for(int i=0; i<n; i++){
            mini = min(mini, a[i]);
            suffMin[i] = mini;
        }
        
        // Sufffix Max Array
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, a[i]);
            suffMax[i] = maxi;
        }
        
        int ans =  -1;
        
        // suffix  >= prefix then increase suffix max index to generate highest index difference else increase prefix min index
        // i =  prefix min index and j = suffix max index😊
        int i=0, j = 0;
        while (i<n && j<n){
            if(suffMin[i] <= suffMax[j]){
                ans = max(ans, j-i);
                j++;
            }
            else{
                i++;
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends