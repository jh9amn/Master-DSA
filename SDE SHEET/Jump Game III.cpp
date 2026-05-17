class Solution {
public:
    bool isValid(int i, int n) {
        return i >= 0 and i < n;
    }
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();
        if(isValid(start, n) and arr[start] == 0) return true;

        // we can solve it without adjecency list as well
        // unordered_map<int, vector<int>> mp;
        // for(int i=0; i<n; i++){ 
        //     if(i + arr[i] < n) {
        //         int u = i + arr[i];
        //         mp[i].push_back(u);
        //     }
        //     if(i - arr[i] >= 0){
        //         int v = i - arr[i];
        //         mp[i].push_back(v);
        //     }
        // }

        queue<pair<int, int>> q;
        q.push({start, arr[start]});

        vector<bool> vis(n, false);
        vis[start] = true;

        // while(!q.empty()) {
        //     auto it = q.front();
        //     q.pop();
        //     int i = it.first;
        //     int val = it.second;

        //     if(val == 0) return true;

        //     for(auto x : mp[i]) {
        //         int newi = x;

        //         if(isValid(newi, n) and !vis[newi]) {
        //             vis[newi] = true;
        //             q.push({newi, arr[newi]});
        //         }
        //     }
        // }

        // Without adjecency
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it.first;
            int val = it.second;

            if(val == 0) return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if(isValid(forward, n)  and !vis[forward]) {
                vis[forward] = true;
                q.push({forward, arr[forward]});
            }
            if(isValid(backward, n)  and !vis[backward]) {
                vis[backward] = true;
                q.push({backward, arr[backward]});
            }
        }
        return false;
    }
};



// DFS
class Solution {
public:
    int N;
    bool dfs(vector<int>& arr, int i, vector<bool> &vis) {
        if(i < 0 || i >= N || vis[i]) {
            return false;
        }

        if(arr[i] == 0) return true;

        vis[i] = true;
        return dfs(arr, i + arr[i], vis) || dfs(arr, i - arr[i], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        N = n;
        vector<bool> vis(n, false);
        return dfs(arr, start, vis);
    }
};
