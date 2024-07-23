#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int it : nums){
            mp[it]++;
        }

        sort(nums.begin(), nums.end(), [&nums, &mp] (int a, int b){
            if(mp[a] == mp[b]){
                if(a > b){
                    return true;
                }
                else return false;
            }

            return mp[a] < mp[b];

        });

        return nums;
    }
};