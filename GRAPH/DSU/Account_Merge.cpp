//{ Driver Code Starts
//Initial Template for C++
// https://practice.geeksforgeeks.org/problems/account-merge/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int find_parent(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_parent(parent[x]);
    }
    
    void Union(int x, int y){
        x = parent[x];
        y = parent[y];
        
        if(x == y) return;
        if(size[x] > size[y]){
            parent[y] = x;
            size[x]++;
        }
        else{
            parent[x] = y;
            size[y]++;
        }
    }
};


class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DSU d(n);
        unordered_map<string,int> mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    d.Union(i,mp[mail]);
                }
            }            
        }
        
        vector<string> mergeMail[n];
        for(auto it : mp){
            string s = it.first;
            int node = d.find_parent(it.second);
            mergeMail[node].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergeMail[i].size() == 0) continue;
            
            sort(mergeMail[i].begin(), mergeMail[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends