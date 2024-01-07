/*
given an array, arr[] containing 'n' intergers, the tast is to 
find an integer (say k) such that after replacing each and every index 
of the array by |(a)i - k| where (i belongs to [1,n]) , result in a sorted array.
If no such integer exists that satisfies the aboe condition then 
return -1.... 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float max(float a, float b){
    if(a>=b){
        return a;
    }    
        else{
            return b;
        }  
}

 float min(float a, float b){
    if(a<b) return a;
    else return b;
}

int main(){
    int arr[] = {5,3,10};
    int n = 3;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    float kmin = (float) (INT_MIN);
    float kmax = (float) (INT_MAX);

    bool flag = true;

    for(int i=0; i<n-1; i++){
        if(arr[i]>=arr[i+1]){
            kmin = max(kmin,(arr[i]+arr[i+1])/2.0);
        } 

        else{
        kmax = min(kmax,(arr[i]+arr[i+1])/2.0);
        }

        if(kmin > kmax){
            flag = false;
            break;
        }
    }

    if(flag == false)  cout<<-1;
    else if(kmin == kmax){
        if(kmin -(int)kmin == 0){
            cout<<"There is only one valse of k :"<<kmin;
        }
        else cout<<-1;
    }
    else{
        if(kmin-(int)kmin>0){
            kmin = (int)kmin + 1;
        }
        cout<<"Range of k is : ["<<kmin<<","<<(int)kmax<<"]";
    }
}