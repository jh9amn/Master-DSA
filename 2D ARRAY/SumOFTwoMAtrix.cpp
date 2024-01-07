#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the row";
    cin >> n;
    cout << "Enter the column";
    cin >> m;

    int arr[n][m];
    cout << "Enter the Elements of 1st matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The first matrix is as" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the Elements of 2nd matrix" << endl;
    int brr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> brr[i][j];
        }
    }

    cout << "The second matrix is as" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The sum matrix is as" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            brr[i][j] += arr[i][j];
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    // sum of both matrix
    // cout<<"The sum of both matrix is as "<<endl;
    // int crr[n][m];
    //   for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //       crr[i][j] = (arr[i][j] + brr[i][j]);
    //        cout<<crr[i][j]<<" ";
    //     }cout<<endl;
    // }
}
