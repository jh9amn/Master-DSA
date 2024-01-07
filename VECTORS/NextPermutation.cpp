// VVVI Ouestion

//Q... Find the next permutaion ...
/*
if input is as 1 2 3
then the next permutation is as 1 3 2

if  the input is as 8 6 4
then the output is as 4 6 8

if the input is as 6 2 4
the then the output is as 6 4 2

if the input is as 2 3 1
the the output is as 3 1 2

if the input is 5 6 4 1
then the output is 6 1 4 5
*/

// step 1.. find the pivot element( v[i] < v[i+1] )
// step 2.. reverse ( (idx+1) to end) where idx = -1
// step 3.. find just greater number to (idx)th element
// step 4.. swapping (idx)th element the (j)th element


#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
    void nextPermutation(vector<int>& v) {
        int n = v.size();

        // finding the pivot element
        int idx = -1;
        for(int i = n-2; i>=0; i--){
            if(v[i]<v[i+1]){
            idx = i;
            break;
        }
      }
      if(idx == -1){
          reverse(v.begin(), v.end());
          return;
      }

      // sorting/reverse afte pivot
    reverse(v.begin()+idx+1,v.end());

    //finding the just greater ele than pivot
    int j = -1;
    for(int i = idx+1; i<n; i++){
        if(v[i] > v[idx]){
            j = i;
            break;
        }
    }

    //swaping idx element with jth element
    int temp = v[idx];
    v[idx] = v[j];
    v[j] = temp;
    return;
    }


 int main(){
    vector<int> vec;
    int n;
    cout<<"Enter the Size ";
    cin>>n;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        vec.push_back(x);
     }
        cout<<"The given vector is as ";
        for(int j = 0; j<n; j++){
        cout<<vec[j]<<" ";
         }cout<<endl;

        nextPermutation(vec);

        cout<<"the Next permutation is as ";
        for(int j = 0; j<n; j++){
        cout<<vec[j]<<" ";
         }
     

}