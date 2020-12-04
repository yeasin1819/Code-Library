#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int l, int r)
{
    if(l >= r) return;
    int idx = l;
    for(int i = l + 1; i <= r; i++)
        if(arr[idx] > arr[i]) idx = i;
    swap(arr[idx], arr[l]);
    selection_sort(arr, l + 1, r);
}

int main()
{

    int t, n, arr[1000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i < n; i++) cin>>arr[i];
        selection_sort(arr, 0, n - 1);
        for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
