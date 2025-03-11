#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp = {{'a',0}, {'b',0}, {'c',0}};
        int left = 0;
        int count = 0;
        int n = s.size();


        for(int right=0; right <= s.size(); right++) {
            mp[s[right]]++;

            while(mp['a'] > 0 and mp['b'] > 0 and mp['c'] > 0) {
                count += n - right;
                mp[s[left]]--;
                left++;
            }
        }
        return count;
    }
};