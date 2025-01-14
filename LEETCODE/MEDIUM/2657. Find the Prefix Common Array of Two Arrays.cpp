#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;

        int n = A.size();
        vector<int> ans(n,0);
        int count = 0;

        for(int i=0; i<n; i++) {
            mp[A[i]]++;
            mp[B[i]]++;

            if(mp[A[i]] == 2)
            {
                count++;
                mp[A[i]]--;
            } 
            if(mp[B[i]] == 2) {
                count++;
                mp[B[i]]--;
            }
            ans[i] = count;
        }

        return ans;
    }
};