//taking inputs  from user

#include<iostream>
#include<vector>
using namespace std;
int main(){
     vector <int> v;
  cout<<"Enter the Size of vector";
  int n;
  cin>>n;

  for(int i = 0;i<n; i++){
    int x;
    cin>>x;
    v.push_back(x);
  }

  for(int j = 0; j<n; j++){
    cout<<v[j]<<" ";
  }
     
}