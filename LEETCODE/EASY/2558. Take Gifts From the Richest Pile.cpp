#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long totalSum = 0;

        for(auto it : gifts){
            totalSum += it;
        }

        priority_queue<int> pq(gifts.begin(), gifts.end());

        long long sqrtEleSum = 0;

        while(k--){                 // O(k)
            int ele = pq.top();     // O(1)
            pq.pop();               // O(logn)

            int remain = sqrt(ele);
            sqrtEleSum += ele - remain;
            pq.push(remain);        // O(logn)
        }

        return totalSum - sqrtEleSum;
    }
};