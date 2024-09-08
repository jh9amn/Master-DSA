#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        int n = nums1.size();
        int m = nums2.size();
        int mid = (n+m)/2;

        int idx1 = mid-1;
        int idx2 = mid;

        int ele1 = -1;
        int ele2 = -1;

        int i = 0;
        int j = 0;

        while(i < n and j < m){
            if(count > mid) break;      // to reduce t.c 
            if(nums1[i] < nums2[j]){
                if(count == idx1) ele1 = nums1[i];
                if(count == idx2) ele2 = nums1[i];

                count++;
                i++;
            }
            else{
                if(count == idx1) ele1 = nums2[j];
                if(count == idx2) ele2 = nums2[j];

                count++;
                j++;
            }
        }

        while(i < n){
            if(count > mid) break;
            if(count == idx1) ele1 = nums1[i];
            if(count == idx2) ele2 = nums1[i];

            count++;
            i++;
        }

        while(j < m){
            if(count > mid) break;
            if(count == idx1) ele1 = nums2[j];
            if(count == idx2) ele2 = nums2[j];

            count++;
            j++;
        }
        
        if((m+n)%2 == 1) return (double) ele2;     // odd length
        return (double)((double)ele1 + double(ele2))/2.0;       // even length
    }
};