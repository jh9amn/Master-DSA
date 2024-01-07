#include<iostream>
#include<Stack>
using namespace std;
int main(){
    int arr[] = {2,4,2,5,7,1,9,6};
    //           -1 2 2 2 5 -1 1 1
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }cout<<endl;

    stack<int> st;
    int pse[n];
    pse[0] = -1;
    st.push(arr[0]);

    for(int i=1; i<n; i++){
        while(st.size()>0 && st.top() >= arr[i]){
            st.pop();
        }
        if(st.size() == 0) pse[i] = -1;
        else pse[i] = st.top();
        st.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout<<pse[i]<<" ";
    }
}