#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> searchRange(vector<int>& arr, int x) {
    vector<int> v;
    int n = arr.size();
    unordered_set <int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }
    if(s.find(x) == s.end()) { // if the ele not present return vector wit -1, -1
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
        
    int low = 0;
    int high = n-1;
    int lb = n;
    int hb = n;
    
      while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            lb = mid;
            high = mid - 1;
        }
        else {
          low = mid+1;
        }
      }

    v.push_back(lb);
      low = 0;
      high = n-1;
      while(low <= high){
        int mid = low + (high-low)/2;
          if(arr[mid] > x){
              hb = mid;
              high = mid - 1;
          }
          else {
              low = mid+1;
          }
      }
    v.push_back(hb-1);
    return v;  
  }
};

int main(){
    
}