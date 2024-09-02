#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    // T.C = O(n)  S.C = O(1)
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int  chalkSum = 0;

        for(int i=0; i<chalk.size(); i++){
            chalkSum += chalk[i];
        }

        int rem = k % chalkSum;

        for(int i=0; i<chalk.size(); i++){
            if(rem < chalk[i]){
                return i;
            }
            rem -= chalk[i];
        }

        return -1;
    }
};