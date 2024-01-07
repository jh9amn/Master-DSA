// Sort the Arrray of Zeros And Ones..

#include<iostream>
#include<vector>
using namespace std;

void sortZeroAndOnes(vector<int> &v){
    int zeros = 0;
    int ones = 0;
    int n = v.size();
    for(int i = 0; i<n; i++){
        if(v[i]==0)  zeros++;
        else  ones++;
    }

    for(int i = 0; i<n; i++){
        if(i<zeros)  v[i] = 0;
        else v[i] = 1;
    }
}

 void sort0sAnd1s(vector<int> &v){
  int n = v.size();
  int i = 0;
  int j = n-1;

//   while(i<j){
//     if(v[i]==0)  i++;
//     if(v[j]==1)  j--;

//     if(i>j)  break;

//      if(v[i] == 1 && v[j] == 0){
//         v[i] = 0;
//         v[j] = 1;
//         i++;
//         j--;
//     }

//   }


   // 2nd way

//     while(i<j){
//     if(v[i]==0)  i++;
//     if(v[j]==1)  j--;

//      else if(v[i] == 1 && v[j] == 0){
//         v[i] = 0;
//         v[j] = 1;
//         i++;
//         j--;
//     }
//   }

    // 3rd way

 while(i<j){
 if(v[i] == 1 && v[j] == 0){
      v[i] = 0;
      v[j] = 1;
      i++;
      j--;
}
    if(v[i]==0)  i++;
    if(v[j]==1)  j--;

  }
}

int main(){
    vector <int> v;
v.push_back(1);
 v.push_back(1);
 v.push_back(0);
 v.push_back(1);
 v.push_back(0);
 v.push_back(1);
 v.push_back(1);
 v.push_back(0); 

for(int i = 0; i<v.size(); i++){
    cout<<v[i]<<" ";
}cout<<endl; 

// sortZeroAndOnes(v) ;

// for(int i = 0; i<v.size(); i++){
//     cout<<v[i]<<" ";
// }

// This is using by just one loop..
sort0sAnd1s(v);
for(int i = 0; i<v.size(); i++){
    cout<<v[i]<<" ";
}

}