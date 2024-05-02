#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        set<int> st;
        int largest = 0;
        for(auto it : nums){
            if(it > 0){
                if(st.find(-it) != st.end() && largest < it) largest = it;
            }
            else{
                if(st.find(-it) != st.end() && largest < -it) largest = -it;
            }
            st.insert(it);
        }
        return largest != 0 ? largest : -1;
    }
};


int main(){

}