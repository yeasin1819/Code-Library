#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(arr[min_idx], arr[i]); 
    } 
} 
int main()
{
    int ara[] = {5, 10, 0, -2, 10};
    selection_sort(ara, 5);
    for(int i = 0; i < 5; i++)
        cout<<ara[i]<<" ";
    return 0;
}
