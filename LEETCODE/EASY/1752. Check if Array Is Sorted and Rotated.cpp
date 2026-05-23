class Solution {
public:
    bool check(vector<int>& nums) {
        // bool check = false;
        // for(int i=1; i<nums.size(); i++) {
        //     if(nums[i] < nums[i-1]) {
        //         if(check) {
        //             return false;
        //         }
        //         check = true;
        //     }
        //     if(check && nums[i] > nums[0]) {
        //         return false;
        //     }
        // }
        // return true;


        int cntDrop = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            // (i + 1) % n seamlessly handles the wrap-around from last to first element
            if(nums[i] > nums[(i+1)%n]) {
                cntDrop++;
            }
            if(cntDrop > 1) {
                return false;
            }
        }

        return true;
    }
};
