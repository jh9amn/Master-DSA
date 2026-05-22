class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;

        while(left <= right) {
            int mid = left + (right - left)/2;

            if(nums[mid] == target) {
                return mid;
            }

            /* Case A: Left side is sorted (nums[left] <= nums[mid]) */
            if(nums[left] <= nums[mid]) {
                // is the target b/w nums[left] and nums[mid]
                //Yes: move right pointer to mid - 1 (search left)
                if(target >= nums[left] and target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }

            /* Case B: Right side is sorted (nums[left] > nums[mid]) */
            else if(nums[left] > nums[mid]) {
                // is the target b/w nums[mid] and nums[right]
                // yes: move left pointer to mid + 1 (search right)
                if(target > nums[mid] and target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
