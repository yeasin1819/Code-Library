#include <bits/stdc++.h>

using namespace std;

int Partition(int arr[], int l, int r)
{
   int pivot = arr[r];
   int i = l;
   for(int j = l; j < r; j++)
   {
       if(arr[j] <= pivot)
       {
           swap(arr[i], arr[j]);
           i++;
       }
   }
   swap(arr[i], arr[r]);
   return i;
}

void QuickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pivotIdx = Partition(arr, l, r);
        QuickSort(arr, l, pivotIdx - 1);
        QuickSort(arr, pivotIdx + 1, r);
    }
    return;
}

int main()
{
    int arr[] = {2, 7, 1, 8, 6, 3, 5, 4};

    QuickSort(arr, 0, 7);

    for(int i = 0; i < 8; i++) cout<<arr[i]<<" ";

    return 0;
}
