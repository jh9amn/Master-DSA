#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size";
    cin >> n;

    int arr[n][n];
    cout <<"Enter the Elements of matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The given matrix is as" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

// transposing the same matrix
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; i++){
            // swapping i,j to j,i
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    cout<<"The Transpose Matrix is as "<<endl;
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}