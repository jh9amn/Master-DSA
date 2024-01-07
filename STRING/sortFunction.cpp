#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
int main(){
    string s = "amrita";
    cout<<s<<endl;
    sort(s.begin(), s.end());
     cout<<s<<endl;
      sort(s.begin()+3, s.end()-2);
     cout<<s<<endl;

}