#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1; // push num one setBit
        }
        return count;
    }

    bool checkSorted(vector<int> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        int k = 0;
        int n = nums.size();

        // Bubble sort..
        while (k < n) {
            for (int i = 0; i < n - 1; i++) {
                int bits = countSetBits(nums[i]);
                int nextBits = countSetBits(nums[i + 1]);

                if (bits == nextBits and nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }

                if (checkSorted(nums))
                    return true;
            }
            k++;
        }
        return n == 1 ? true : false;
    }
};