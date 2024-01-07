// ques --> minimum room required to do meeting  leetcode 252

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minMeetingRoom(vector<vector<int> > &a) {
        sort(a.begin(),a.end());
        priority_queue<int,vector<int>, greater<int> > pq;
        for(int i=0; i<a.size(); i++){
            if(pq.empty()) pq.push(a[i][1]);
            else{
                if(pq.top() <= a[i][0]) {
                    pq.pop();
                    pq.push(a[i][1]); 
                }
                else{
                    pq.push(a[i][1]);
                }
            }
        }
        return pq.size();
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {
        {0,30},
        {5,10},
        {15,20}
    };
    cout<<s.minMeetingRoom(v);
}


// Another Way to do this
class Sol{
    public:
        int solve(vector<vector<int> > &v) {
        vector<int> start;
        vector<int> endd;
        for(auto ele : v){
            start.push_back(ele[0]);
            endd.push_back(ele[1]);
        }
        sort(start.begin(),start.end());
        sort(endd.begin(),endd.end());
        
        int i=0, j=0;
        int ans = 0;
        int room = 0;
        
        while(i<start.size() && j<endd.size()){
            if(start[i] < endd[j]) {
                room++;
                ans = max(room,ans);
                i++;
            }
            else if(start[i] > endd[j]){
                room--;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};