#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
string s = "egg";
string t = "add";

  if(s.length() != t.length())  cout<<false<<endl;

     vector <int> v(150,1000);
     for(int i=0; i<s.length(); i++){
         int idx = (int)s[i];
        if(v[idx]==1000)  v[idx] = s[i] - t[i];
        else if(v[idx] != (s[i]-t[i]))  cout<<false<<endl;
     }

        // empty the vector 
        for(int j=0; j<150; j++){
            v[j] = 1000;
        }
            for(int i=0; i<s.length(); i++){
                int idx = (int)t[i];
                if(v[idx] == 1000)  v[idx] = t[i] - s[i];
                else if(v[idx] != (t[i] - s[i]))  cout<<false<<endl;
            }

        
            cout<<true;
        
    }
