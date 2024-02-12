#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                v[i]++;
            }
            if( v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                 else{
                    v[i]=1;
                    v.push_back(0);
                }
            }
            
        }
        return v;
        
    }
};

int main(){

}