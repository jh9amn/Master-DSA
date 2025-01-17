#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // lets assum the original array of size n
        // first assume original[n-1] == 0

        int n = derived.size();
        vector<int> original(n,0);

        for(int i=n-2; i>=0; i--) {
            original[i] = derived[i] ^ original[i+1];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        // now assume original[n-1] == 1;

        original[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            original[i] = derived[i] ^ original[i+1];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        return false;
    }
};

/*
-> original[i] ^ original[i+1] = derived[i];
-> original[i] = original[i+1] ^ derived[i];

*/