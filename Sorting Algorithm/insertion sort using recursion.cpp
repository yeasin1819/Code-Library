#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int n)
{
    if(n <= 0) return;
    insertion_sort(arr, n - 1);
    int key = arr[n];
    int i = n - 1;
    while(i >= 0 && arr[i] > key) swap(arr[i], arr[i + 1]), i--;
}

int main()
{
    int ara[] = {100, 10, 50, 2, 90, 0};
    insertion_sort(ara, 6);
    for(int i = 0; i < 6; i++)
        cout<<ara[i]<<" ";
    return 0;

    return 0;
}
