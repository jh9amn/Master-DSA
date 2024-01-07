#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int minProduct(vector<int> &v){
    int count_neg = 0;
    int count_pos = 0;
    int count_zero = 0;
    int prod_neg = 1;
    int prod_pos = 1;
    int largest_neg = INT_MIN;
    int minimum_pos = INT_MAX;

    for(int i=0; i<v.size(); i++){
        if(v[i] == 0) count_zero++;
        else if(v[i] > 0) {
            prod_pos *= v[i];
            count_pos++;
            minimum_pos = min(minimum_pos,v[i]);
        }
        else { // (v[i] < 0) for negative element
            prod_neg *= v[i];
            count_neg++;
            largest_neg = max(largest_neg , v[i]) ;
        }
    }

    if(count_zero > 0)  return 0;
    else if(count_neg > 0){
        if(count_neg%2 != 0){
            // odd no of negative element
            return prod_neg * prod_pos;
        }
        if(count_neg%2 == 0){
            // even no of negative element
            return (prod_neg / largest_neg) * prod_pos;
        }
    }
    else return minimum_pos ;
}
int main(){
    // vector<int> v = {-2,-3,1,4,-2,-5}; // while has even no of negative element
    // vector<int> v = {0,1,4,2,6};  // which has zero
    vector<int> v = {5,4,23};    // for all positive element
    // vector<int> v = {-2,-3,1,4,-5}; //  which has odd no of negative element
    cout<<"The min Product is as : "<<minProduct(v);

}