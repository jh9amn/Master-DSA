#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> totalOr;
        unordered_set<int> prevOr;

        for(int i=0; i<n; i++) {    // O(n)
            unordered_set<int> currOr;
            // OR  till prev index OR value and store
            for(auto s : prevOr) {  // O(32) bits 
                currOr.insert(s | arr[i]);
                totalOr.insert(s | arr[i]);
            }
            // OR of ith index value
            currOr.insert(arr[i]);
            totalOr.insert(arr[i]);
            prevOr = currOr;
        }
        return totalOr.size();
    }
};


/* 
| Case    | Time Complexity              | Space Complexity         |
| ------- | ---------------------------- | ------------------------ |
| Average | **O(n × log(max\_element))** | O(n × log(max\_element)) |
| Worst   | O(n²)                        | O(n²)                    |
*/
