#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    
    int maxScoreSightseeingPair(vector<int>& values) {

        /* Approach 1
         Brute Force TLE */
        int maxi = INT_MIN;
        int n = values.size();
        
        for(int i=0; i<n; i++){
            int currMaxi = 0;

            for(int j=i+1; j<n; j++){
                int val = values[i] + values[j] + i - j;
                currMaxi = max(val, currMaxi );
            }
            maxi = max(maxi, currMaxi);
        }
        return maxi;

        

        /* Approach 2..
        Keep track of values[i] + i as max
        and iterarte the through again then substract  values[j] - j 
        which give us max out our answer */

        int n = values.size();
        vector<int> vec(n,0);
        int ansMaxi = INT_MIN;

        vec[0] = values[0] + 0;

        for(int i=1; i<n; i++){
            vec[i] = max(vec[i-1], values[i] + i);
        }

        for(int j=1; j<n; j++){
            int x = values[j] - j;
            int y = vec[j-1];       

            ansMaxi = max(ansMaxi, x + y);
        }

        return ansMaxi;


        /* Space Optimized */
        int n = values.size();
        int ansMaxi = INT_MIN;
        int tillMax = 0;

        tillMax = values[0] + 0;

        for(int j=1; j<n; j++){
            int x = values[j] - j;
            int y = tillMax;       

            ansMaxi = max(ansMaxi, x + y);

            tillMax = max(tillMax, values[j] + j);
        }

        return ansMaxi;
    }
};