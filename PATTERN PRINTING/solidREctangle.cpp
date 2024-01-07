// *****
// *****
// *****
// *****

#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter numbers of row And column";
    cin>>n>>m;
    for(int i= 1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<"*";
        }
          cout<<endl;
    }
}


// Another Way
/*#include<iostream>
using namespace std;
int main(){
    int n;
    for(int i=1; i<=n; i++){
        cout<<"*****"<<endl;
    }
}*/