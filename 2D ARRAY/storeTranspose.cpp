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

    cout << "The given matrix is as" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

  int trr[m][n];

    cout<<"The stores Transpose MAtrix is as"<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           trr[i][j] = arr[j][i];
           cout<<trr[i][j]<<" ";
        }
        cout << endl;
    }

  
}