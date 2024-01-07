// 2nd largest Elements in the 2d Array

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter the Rows";
    cin >> m;
    cout << "Enter the Columns";
    cin >> n;

    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max = INT_MIN;
    int min = arr[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
    }

    cout<<"The max Element is as "<<max<<endl;

    
    cout<<"The 2nd greatest Element is as "<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j] != max) && (min < arr[i][j]))
            {
                min = arr[i][j];
            }
        }
    }    cout << min;

    return 0;
}