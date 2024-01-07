#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortMethode1(vector<int> &v){
  int  n = v.size();
  int countZero = 0;
  int countOnes = 0;
  int countTwoes = 0;
 for(int i = 0; i<n; i++){
     if(v[i] == 0)  countZero ++;
     else if(v[i] == 1) countOnes++;
     else countTwoes++;
 }
 for(int i = 0; i<n; i++){
     if( i < countZero)  v[i] = 0;
     else if( i <(countZero+countOnes)) v[i] = 1;
     else v[i] = 2;
 } return;
}

void SortMethode2(vector<int> &v){
 int n = v.size();
 int low = 0;
 int mid = 0;
 int high = n-1;
 while(mid<=high){
     if(v[mid]==2){
        int temp;
        temp = v[mid];
        v[mid] = v[high];
        v[high] = temp;
        high --;
     }
     else if(v[mid] == 0){
        int temp = v[mid];
        v[mid] = v[low];
        v[low] = temp;
        low++;
        mid++;
     }
     else{
        mid ++; 
     }
 }
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);

    int n = v.size(); 

    cout<<"the given array is as ";
      for(int i = 0; i<n; i ++){
     cout<<v.at(i)<<" ";
}  cout<<endl;
    // sort(v);
     SortMethode2(v);
     for(int i = 0; i<n; i ++){
     cout<<v.at(i)<<" ";
}
}