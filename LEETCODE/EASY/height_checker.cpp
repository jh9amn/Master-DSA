#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        
        int count = 0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != temp[i]) count++;
        }
        return count;
    }
};


int main(){}