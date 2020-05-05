#include <bits/stdc++.h>

using namespace std;

int upper(int ara[], int l, int r, int x)
{
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(ara[mid] >= x) r = mid - 1;
        if(ara[mid] < x) l = mid + 1;
        if((l == mid) && (ara[mid] >= x)) return mid;
        if((ara[mid] < x) && (ara[mid + 1] >= x))return mid + 1;
        if((r == mid) && (ara[mid] < x)) return -1; ///not found.
    }
}
int lower(int ara[], int l, int r, int x)
{
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(ara[mid] > x) r = mid - 1;
        if(ara[mid] <= x) l = mid + 1;
        if((r == mid) && (ara[mid] <= x)) return mid;
        if((ara[mid] <= x) && (ara[mid + 1] > x)) return mid;
        if((l == mid) && (ara[mid] > x)) return -1;///not found
    }
}
int main()
{
    int ara[] = {1, 4, 6, 8, 10};
    cout<<upper(ara, 0, 4, 6)<<endl;
    cout<<lower(ara, 0, 4, 1)<<endl;
    return 0;
}
