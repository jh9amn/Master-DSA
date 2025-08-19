#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
private:
    double const epsilon = 0.1;
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        // for real divions array should be in double
        for(auto it : cards) {
            nums.push_back(1.0 * it);
        }

        function<bool(vector<double> &)> solve = [&](vector<double> &nums){
            if(nums.size() == 1) {
                if(abs(nums[0] - 24) <= epsilon) return true;
            }


            for(int i=0; i<nums.size(); i++) {
                for(int j=0; j<nums.size(); j++) {
                    // not perform operation with same number
                    if(i == j) continue;


                    vector<double> temp;
                    // insert remaing numbers
                    for(int k=0; k<nums.size(); k++ ){
                        if(k != i && k != j) {
                            temp.push_back(nums[k]);
                        }
                    }
                    
                    // perform operation onto these numbers
                    // Operation like : +, -, *, /
                    double a = nums[i];
                    double b = nums[j];

                    vector<double> possibleVal = {a+b, a-b, b-a, a*b};
                    if(b != 0.0) possibleVal.push_back(a/b);
                    if(a != 0.0) possibleVal.push_back(b/a);

                    for(auto it : possibleVal) {
                        temp.push_back(it);
                        if(solve(temp)) return true;
                        temp.pop_back();
                    }
                }
            }
            return false;
        };
        
        return solve(nums);
    }
};