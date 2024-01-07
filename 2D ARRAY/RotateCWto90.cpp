// rotate the squre matrix clock-wise to 90 degree..

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

// tranposing the matrix..
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp ;
            }
        }

// now reversing/swapping the each row element
        for(int k = 0; k<n; k++){
            int i=0;  // two pointers
            int j=n-1;
            while(i<=j){
                int temp = matrix[k][i];  // here rows are constant
                matrix[k][i] = matrix[k][j];
                matrix[k][j] =temp;
                i++;
                j--;
            }
        }

        return ;
    }


    int main(){
        cout<<"Enter the Size";
        int n;
        cin>>n;
        vector<vector<int>>  v(n, vector<int>(n));
        v.push_back(7);
    

    }

