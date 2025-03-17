#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // 1st way: HashMap

        // unordered_map<int, int> mp;

        // for(auto it : nums) {
        //     mp[it]++;
        // }

        // for(auto it : mp) {
        //     if(it.second % 2 == 1) return false;
        // }
        // return true;


        // 2nd way: HashSet

        // unordered_set<int> st;
        // for(auto it : nums) {
        //     if(st.count(it)) {
        //         st.erase(it);
        //     }
        //     else {
        //         st.insert(it);
        //     }
        // }
        // return st.size() == 0;

        // 3rd way: Sorting

        // sort(begin(nums), end(nums));
        // int i=1;
        // for(i; i<nums.size();) {
        //     if(nums[i] != nums[i-1]) return false;
        //     i+=2;
        // }
        // return true;


        // 4th way: XOR

        // sort(begin(nums), end(nums));
        // for(int i=0; i<nums.size(); i+=2) {
        //     int XOR = nums[i] ^ nums[i+1];
        //     if(XOR != 0) return false;
        // }
        // return true;


        // 5th Way: Frequency Array
        
        vector<bool> f(501,true);
        for(int i=0; i<nums.size(); i++) {
            f[nums[i]] = !f[nums[i]];
        }

        for(int i=0; i<501; i++) {
            if(f[i] == false) return false;
        }
        return true;
    }
};