#include<iostream>
using namespace std;
int main(){
    char ch ;
    cout<<"entter A Alphabats ";
    cin>>ch;

    if((ch>=67 && ch<=90)  || ch>=97 && ch<=122 ){
        if((ch=='a'||'A') || (ch=='e'||'E') || (ch=='i'||'I') || (ch=='o'||'O') || (ch=='u'||'U')){
            cout<<"IF is a vowel";
    }
    else {
    cout<<" It is a Consonent";
    }
    } else{
        cout<<"Not An alphabats";
    }

}