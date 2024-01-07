#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[] = {2,3,5,2,6,8,3,1};
            //   1 2 2 1 3 3 1 -1  
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    stack<int> st;
    int nse[n];
    nse[n-1] = -1;
    st.push(arr[n-1]);
    for(int i=n-2; i>=0; i--){
        while(st.top() > 0 && st.top() >= arr[i]){
            st.pop();
        }
        if(st.size() == 0)  nse[i] = -1;
        else  nse[i] = st.top();
        st.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout<<nse[i]<<" ";
    }cout<<endl;

}
