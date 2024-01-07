// count max no of times charactor parents

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "ammmmaaan";
    int max = 0;
    for(int i=0; i<s.size(); i++){
        char ch=s[i];
        int count = 1;
        for(int j=i+1; j<s.size(); j++){
            if(s[j] == s[i])  count++;
        }
        if(max < count)  max = count;
    } 

    for(int i=0; i<s.size(); i++ ){
        char ch = s[i];
        int count = 1;
        for(int j=i+1; j<s.size(); j++){
            if(s[j] == s[i])  count++;
        }
        if(count==max)
        cout<<ch<<" "<<max<<endl;
    }
}
