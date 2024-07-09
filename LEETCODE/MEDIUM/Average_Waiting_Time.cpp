#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0.0;
        bool flag = false;
        double avgWait = 0.0;
        for(auto it : customers){
            if(!flag){
                wait = it[0] + it[1];
                flag = true;
                avgWait = wait - it[0];
            }else {
                // if the chef get rest because customer come later
                if(wait < it[0]) {
                    wait = it[0] + it[1];
                    avgWait += wait - it[0];
                }
                else {
                    wait += it[1];
                    avgWait += abs(wait - it[0]);
                }
            }
        }
        return avgWait / customers.size();
    }
};

int main(){

}