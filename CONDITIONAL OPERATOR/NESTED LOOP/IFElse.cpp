
#include<iostream>
using namespace std;
int main(){
    int marks;
    cout<<"enter the marks";
    cin>>marks;

if(marks>=91){
        cout<<"Execellent";
    }
    else{
        if(marks>=81){
            cout<<"Very Good";
        }
        else{
            if(marks>=71){
                cout<<"Good";
            }
            else{
                if(marks>=61){
                    cout<<"can Do better";
                }
                else{
                    if(marks>=51){
                        cout<<"Average";
                    }
                    else{
                        if(marks>=41){
                            cout<<"Below Average";
                        }
                        else{
                         cout<<"Fail";
                        }
                    }
                }
            }
        }
    }
}


