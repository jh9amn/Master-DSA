#include<bits/stdc++.h>
using namespace std;
int main(){}

/* With simple array using approach which is giving TLE */
class NumArray {
private:
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        this->arr = nums;
    }
    
    void update(int index, int val) {
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i=left; i<=right; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

/********************************************************************************/

/* Segment Tree approach */
// The maximum node idx can go upto 4 * n 

class NumArray {
private:
    int n;
    vector<int> arr; 
    vector<int> seg;

    void buildSegmentTree(int nodeIdx, int low, int high) {
        if(low == high) {
            seg[nodeIdx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        int leftNodeIdx = 2 * nodeIdx + 1;
        int rightNodeIdx = 2 * nodeIdx + 2;
        buildSegmentTree(leftNodeIdx, low, mid);   // left node
        buildSegmentTree(rightNodeIdx, mid + 1, high);   // right node
        seg[nodeIdx] = seg[leftNodeIdx] + seg[rightNodeIdx];
    }

    /* 
        TO FIND QUERY SUM INTO RANGE    
    There are three observation to find range sum
    1) completely lies in range then return ans
    2) not lies in range return INT_MIN
    3) overlap or partialy overlap -> then go left nodeIdx and right nodeIdx
    */
    int querySum(int nodeIdx, int start, int end, int left, int right) {
        // if completly lies into range then return ans
        if(start >= left and end <= right) {
            return seg[nodeIdx];       
        }

        // if not lies into range
        if(start > right || end < left) {
            return 0;
        }

        // if overlap or partialy overlap into range
        int mid = start + (end - start) / 2;
        int leftNodeIdx = 2 * nodeIdx + 1;
        int rightNodeIdx = 2 * nodeIdx + 2;
        int leftSum = querySum(leftNodeIdx, start, mid, left, right);
        int rightSum = querySum(rightNodeIdx, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

    void updateTree(int nodeIdx, int start, int end, int idx, int val) {
        if(start == end) {
            arr[idx] = val;
            seg[nodeIdx] = val;
        }

        else {
            int mid = start + (end - start) / 2;
            int leftNodeIdx = 2 * nodeIdx + 1;
            int rightNodeIdx = 2 * nodeIdx + 2;
            if(mid >= idx) 
                updateTree(leftNodeIdx, start, mid, idx, val);
            else
                updateTree(rightNodeIdx, mid+1, end, idx, val);
            seg[nodeIdx] = seg[leftNodeIdx] + seg[rightNodeIdx];
        }
    }

public:
    NumArray(vector<int>& nums) {
        this -> arr = nums;
        n = arr.size();
        seg.resize(4 * n);
        buildSegmentTree(0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
                    // idx, start, end, left, right
        return querySum(0, 0, n-1, left, right);        
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */