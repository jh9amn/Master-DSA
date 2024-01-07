/* Move all negative numbers to beginning and
positive to end with constant extra spaces..*/

#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &v){
int n = v.size();
int i = 0;
int j = n-1;
int temp = 0 ;
while(i<j){
    if(v[i] < 0) i++;
    if(v[j] > 0) j--;

if (v[i]>=0 && v[j]<=0){
     temp = v[i];
     v[i] = v[j];
     v[j] = temp;
     i++;
     j--;
}
}
}
int main(){
    vector <int> v;
    
    v.push_back(1);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(-4);
    v.push_back(-5);
    v.push_back(0);
    v.push_back(8);
    v.push_back(-7); 

    int n = v.size();

  for(int i=0; i<n; i++){
        cout<<v.at(i)<<" ";
    } cout<<endl;
    sort(v);

    for(int i=0; i<n; i++){
        cout<<v.at(i)<<" ";
    }
}
