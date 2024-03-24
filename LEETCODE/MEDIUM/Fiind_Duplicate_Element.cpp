class Solution {
public:
    int findDuplicate(vector<int>& nums) { 
//      Using Binary Search Apporach     T.C = O ( n * log(n))
//         int start = 1;
//         int end = nums.size() -1;
        
//         while(start < end){
//             int mid = start + (end - start)/2;
//             int count = 0;
            
//             for(auto it : nums){
//                 if(mid >= it){
//                     count++;
//                 }
//             }
//             if(count > mid){
//                 end = mid;
//             }
//             else {
//                 start = mid + 1;
//             }
//         }
//         return start;
        

        
//      Two Pointer Approach  T.C = O (N)  S.C = O (1)
//         int slow = nums[0];
//         int fast = nums[0];
//         do {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }
//         while(slow != fast);
        
//         fast = nums[0];
//         while( slow != fast){
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }
//         return slow;
        

        
// One pointer Approach but modification in array    T.C = O (N)  S.C = O (1)
        int i=0;
        while (nums[i] > 0){
            int tmp = nums[i];
            nums[i] = 0;
            i = tmp;
        }
        return i;
    }
};