#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), [](int a, int b){
            string x = to_string(a) + to_string(b);
            string y = to_string(b) + to_string(a);
            return x > y;
        });
        
        string ans = "";
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        
        if(ans[0] == '0') return "0";
        return ans;
    }
};


int main(){

}