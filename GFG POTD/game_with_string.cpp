//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        vector<int> v(26,0);
        priority_queue<int, vector<int>> pq;

        
        for(int i=0; i<s.size(); i++){
            v[s[i] - 'a']++;
        }

        for(int i=0; i<v.size(); i++){
            pq.push(v[i]);
        }
        
        while(k > 0){
           int curr = pq.top();
           pq.pop();
           pq.push(curr - 1);
           k--;
        }
        
        int ans = 0;
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            ans += curr * curr;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends