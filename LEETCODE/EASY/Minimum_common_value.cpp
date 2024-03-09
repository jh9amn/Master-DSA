#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // if anyone starting element is greater than othe vector last elements
        if(nums1[nums1.size()-1] < nums2[0]) return -1;
        if(nums1[0] > nums2[nums2.size()-1]) return -1;
        
        int i = 0 , j = 0;
        int smaller = INT_MAX;
        while( i < nums1.size() && j < nums2.size()){
           if(nums1[i] == nums2[j]){
               smaller = min (nums1[i], smaller);
               i++;
               j++;
           }
            else{
                if(nums1[i] < nums2[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
        }
        return smaller != INT_MAX ? smaller : -1;
    }
};

int main(){

}