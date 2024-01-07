// Meeting Room 1 LEETCODE 252
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution{
    public:
    bool canAttendMeeting(vector<vector<int>> &v){
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        for(int i=0; i<v.size(); i++){
            if(pq.empty()) pq.push(v[i][1]);
            else{
                if(pq.top() < v[0][i]) {
                    pq.pop();
                    pq.push(v[i][1]);
                }
                else {
                    pq.push(v[1][1]);
                }
            }
        }
        if(pq.size() > 1) return false;
        return true;
    }
};



int main(){
    Solution s;
    vector<vector<int>> v = {
        {0,30},
        {5,10},
        {15,20}
    };
    cout<<s.canAttendMeeting(v);
}