  #include<bits/stdc++.h>
  using namespace std;
    vector<int> find(int arr[], int n , int x )
    {
        int start,end;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            if(arr[i] == x) {
                v.push_back(i);
            }
        }
        for(int i=0; i<v.size(); i++){
            start = v[0];
            end = v[v.size()-1];
        }
        v.clear();
        v.push_back(start);
        v.push_back(end);
        return v;
    }

    int main(){
        int n = 9;
        int x = 3;
        int arr[] = {1, 3, 3, 5, 5, 5, 67, 123, 125};
        vector<int> v = find(arr,n,x);
        for(int i=0; i<2; i++){
            cout<<v[i]<<" ";
        }

    }