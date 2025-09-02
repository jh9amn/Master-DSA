#include<bits/stdc++.h>
using namespace std;
int main() {}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // double total = 0.0;
        // double maxi = 0.0;
        // int n = classes.size();

        // for(auto &it : classes){
        //     int a = it[0];
        //     int b = it[1];

        //     double val = double(a)/b; 
        //     total += val;
        // }

        // for(auto &it : classes){
        //     int a = it[0];
        //     int b = it[1];

        //     double val = double(a)/b; 
        //     total -= val;

        //     a += extraStudents;
        //     b += extraStudents;

        //     double extraVal = double(a)/b; 
        //     total += extraVal;

        //     if(maxi < total) {
        //         maxi = total;
        //     }

        //     total -= extraVal;
        //     total += val;
        // }

        // return maxi/n;

        /*
        ** to solve this, have to check with every class that which one is giving max avg ratio
        ** to struct it, use max heap, and store, [diff of pass and total avg ratio class, pass student, total student]
        */

        // which will give the max increament in ratio 
        function<double(int, int)> calculateMaxGain = [&](int a, int b) {
            return double(a+1) / (b+1) - (double(a) / b);
        };

        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;      // max heap ->, max increase in ration, pass, total student

        for(auto &it : classes) {
            int a = it[0];
            int b = it[1];

            double givesMaxIncreament = calculateMaxGain(a, b);
            pq.push({givesMaxIncreament, {a, b}});
        }

        while(extraStudents--){
            auto it = pq.top();
            pq.pop();

            int a = it.second.first + 1;
            int b = it.second.second + 1;

            double givesMaxIncreament = calculateMaxGain(a, b);
            pq.push({givesMaxIncreament, {a, b}});
        }

        double total = 0.0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int a = it.second.first; 
            int b = it.second.second;

            total += double(a) / b;
        }

        return total / n;
    }
};



