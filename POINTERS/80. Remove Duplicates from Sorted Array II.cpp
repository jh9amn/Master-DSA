#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // using extra space O(n)
        int i = 0;
        unordered_map<int, int> mp;

        for(auto it : nums) {
            if(mp[it] < 2) {
                mp[it]++;
            }
        }

        for(int k=0; k<nums.size(); k++) { 
            int a = nums[k];

            if(mp[a] > 0){
                nums[i] = nums[k];
                mp[a]--;
                i++;
            }
        }
        return i;
    }
};


/* two pointer approach without using extra space*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 2;
        if(nums.size() < 2) return nums.size();
        for(int i=2; i<nums.size(); i++) {
            if(nums[i] != nums[j-2]) {
                nums[j++] = nums[i];
            }
        }
        return  j;
    }
};