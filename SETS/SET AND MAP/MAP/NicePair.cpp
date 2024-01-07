#include<iostream>
#include<unordered_map>
using namespace std;
int rev(int n){
    int r = 0;
    while(n > 0){
        r = r*10;
        r = r + (n%10);
        n = n/10;
    }
    return r;
}

void nicePair(int arr[],int n){
    int count = 0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        arr[i] -= rev(arr[i]);
    }
    for(int i=0; i<n; i++){
         if(m.find(arr[i]) != m.end()){
            count += m[arr[i]];
            m[arr[i]]++;
         }
         else{
            m[arr[i]]++;
         }
    }
    cout<<count;
}

int main(){
    int arr[] = {13,10,35,24,76};
    int n = sizeof(arr) /sizeof(arr[0]);
    nicePair(arr,n);
}
