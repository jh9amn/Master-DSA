#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:

    void merge(vector<int> &nums, int s, int m, int e){
        int n1 = m - s + 1;
        int n2 = e - m;

        vector<int> a(n1);
        vector<int> b(n2);

        for(int i=0; i<n1; i++) {
            a[i] = nums[i+s];
        }

        for(int i=0; i<n2; i++){
            b[i] = nums[m+i+1];
        }

        int i=0;
        int j=0; 
        int k=s;

        while(i < n1 and j < n2){
            if(a[i] <= b[j]){
                nums[k] = a[i];
                i++;
            }
            else {
                nums[k] = b[j];
                j++;
            }
            k++;
        }

        while(i < n1){
            nums[k] = a[i];
            i++;
            k++;
        }
        while(j < n2){
            nums[k] = b[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int> &nums, int s, int e){
        if(s == e) return;
        int m = (s+e) /2;
        mergeSort(nums, s, m);
        mergeSort(nums, m+1, e);
        merge(nums, s, m, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};