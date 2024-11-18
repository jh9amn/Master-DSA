#include<bits/stdc++.h>
using namespace std;
int main(){

}


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int cnt = abs(k);
            int sum = 0;
            if(k > 0){
                int j = i+1;
                while(cnt--){
                    if(j == n) j = 0;
                    sum += code[j];
                    j++;
                }
            }
            else if(k < 0){
                int j = i-1;
                while(cnt--){
                    if(j < 0) j = n-1;
                    sum += code[j];
                    j--;
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};