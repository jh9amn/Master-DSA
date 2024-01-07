
//Merging the two Sorted Array

#include<iostream>
#include<vector>
using namespace std;
vector<int> merge(vector<int> &v1,vector<int> &v2){
    int n = v1.size();
    int m = v2.size();
    vector <int> res(m+n);
     int i = 0;
     int j = 0; 
     int k = 0;

     while(i<=n-1 && i<=m-1){
        if(v1[i]<v2[j]){
            res[k] = v1[i];
            i++;
            k++;
        }
        else {
            res[k] = v2[j];
            j++;
            k++;
        }
     }

     if(i==n){
        while(j<=m-1){
            res[k] = v2[j];
            k++;
            j++;
        }
     }

     if(j==m){
        while(i<=n-1){
            res[k] = v1[i];
            k++;
            j++;
        }
     }
     return res;
}


int main(){
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(7);


    for(int i = 0; i<v1.size(); i++){
   cout<<v1[i]<<" ";
   }cout<<endl;

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(6);
    v2.push_back(8);
    v2.push_back(9);
    v2.push_back(10);
    v2.push_back(11);


     for(int i = 0; i<v2.size(); i++){
   cout<<v2[i]<<" ";
   }cout<<endl;
   

   vector<int> v = merge(v1,v2);

   cout<<"The Merge Vector is as "<<endl;
   for(int i = 0; (i<v1.size()+v2.size()); i++){
   cout<<v[i]<<" ";
   }
}
