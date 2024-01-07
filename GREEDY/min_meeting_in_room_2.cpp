#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &v) {
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>, greater<int> > pq;
        for(int i=1; i<v.size(); i++ ){
            if(pq.empty()){
                pq.push(v[i][1]);
            }
            else{
                if(pq.top() <= v[i][0]){
                    pq.pop();
                    pq.push(v[i][1]);
                }
                else{
                    pq.push(v[i][1]);
                }
            }
        }
        return pq.size();
    }
};

int main(){
     vector<vector<int>> v {{0,30},               
                          {5,10} ,
                          {15,20} };   //2
    Solution s;
    cout<<s.minMeetingRooms(v);
}