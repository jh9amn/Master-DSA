#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        
        int platform = 0;
        int maxPlatform = 0;
        
        int i = 0, j = 0;
        int n = arr.size();
        
        while(i < n and j < n) {
            // train arrive beform any train depart
            if(arr[i] <= dep[j]) {
                platform++;
                i++;
            }
            // train depart so here new train can arrive
            else{
                platform--;
                j++;
            }
            
            maxPlatform = max(platform, maxPlatform);
        }
        
        return maxPlatform;
    }
};