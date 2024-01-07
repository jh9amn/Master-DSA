 // Insertion sort
 
 #include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 int main(){

    vector<int> v;

    v.push_back(5);
    v.push_back(-10);
    v.push_back(7);
    v.push_back(-1);
    v.push_back(5);
    v.push_back(8);
    v.push_back(-13);

    int n = v.size();

    cout<<"The Given vector is as ";
    for(int ele:v){
        cout<<ele<<" ";
    }cout<<endl;

    // INSERTIION SORT ALGORITHM
    // for(int i=1; i<n; i++){
    //     int j = i;
    //     while(j>=1){
    //         if(v[j-1] <= v[j])  break;

    //         else   
    //         swap(v[j-1], v[j]);
    //         j--;
        
    //         }
    // }

    // Another way to write

    for(int i =1; i<n; i++){
        int j=i;
        while(j>=1 &&  (v[j] < v[j-1])){
            swap(v[j], v[j-1]);
            j--;
        }
    }

    cout<<"The Insertion Sorted vector is as ";
    for(int ele:v){
        cout<<ele<<" ";
    }cout<<endl;

 }

 // time complexity

 // wrost case = O(n2)
// Avg case    = O(n2)
// best case   = O(n)