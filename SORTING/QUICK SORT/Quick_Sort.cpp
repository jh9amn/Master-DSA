//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
       if(low < high){
           // finding the right place of Pivot and the apply
           // qs of left side element which are lesser than pivot 
           // and rigth side of element whose are greater then the pivot
            int patitionIdx = partition(arr, low, high);
            quickSort( arr , low, patitionIdx - 1);
            quickSort( arr , patitionIdx + 1, high);
        }
    }

    public:
    int partition (int arr[], int low, int high)
    {
       int i = low;
       int j = high;
       int pivot = arr[low];
        while( i < j){
            // find idx which has val greater than pivot idx
            while( pivot >= arr[i] && i <= high - 1){
                i++;
            }
            // find idx which has val smaller than pivot idx  
            while( pivot < arr[j] && j >= low + 1){
                j--;
            }
            
            if( i < j) swap(arr[i], arr[j]);
        }
        
        // when j cross i ( j < i)
        swap(arr[j] , arr[low]);
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends