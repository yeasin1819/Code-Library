#include <bits/stdc++.h>

using namespace std;

int upper(int arr[], int l, int r, int x)
{
    int last = r;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= x) r = mid - 1;
        else if(arr[mid] < x) l = mid + 1;
    }
    if(l > last) return -1;
    return l;
}
int lower(int arr[], int l, int r, int x)
{
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] <= x) l = mid + 1;
        else if(arr[mid] > x) r = mid - 1;
    }
    return r;
}
int main()
{
    int ara[] = {1, 4, 6, 8, 10};
    cout<<upper(ara, 0, 4, 6)<<endl;
    cout<<lower(ara, 0, 4, 1)<<endl;
    return 0;
}
