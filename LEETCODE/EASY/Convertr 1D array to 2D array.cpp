#include<bits/stdc++.h>
using namespace std;
int main(){}
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size() != m * n) return ans;
        int k = 0;
        while(k < m){
            int start = k * n;
            int end = start + n;
            vector<int> slicedArray(original.begin() + start, original.begin() + end);
            ans.push_back(slicedArray);
            k++;
        }
        return ans;
    }
};