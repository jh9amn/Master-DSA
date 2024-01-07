Q...https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> fibo(vector<int> &v, int k){
    int a = 1; 
    int b = 1;
    v.push_back(a);
    v.push_back(b);
        for(int i=0;; i++){
            int c = a+b;
            if(c>k) break;
            v.push_back(c);
            a = b;
            b = c;
        }
        return v;
    }
    int findMinFibonacciNumbers(int k) {
        vector<int> v;
        fibo(v,k);
        int count = 0;
        while(k>0){
            if(v.back() > k){
                v.pop_back();
                continue;
            }
            count++;
            k -= v.back();
            v.pop_back();
        } 
        return count;  
    }
};

int main(){

}