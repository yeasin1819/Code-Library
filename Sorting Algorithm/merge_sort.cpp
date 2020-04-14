#include <bits/stdc++.h>

using namespace std;

void merge_sort(int ara[], int l, int r)
{
    if(l == r) return;
    int mid = l + (r - l) / 2;
    merge_sort(ara, l, mid);
    merge_sort(ara, mid + 1, r);
    int temp[r-l+1], k = 0, i= l, j = mid+1;
    while((i <= mid) && (j <= r))
    {
        if(ara[i] < ara[j]) temp[k++] = ara[i++];
        else temp[k++] = ara[j++];
    }
    while(i <= mid) temp[k++] = ara[i++];
    while(j <= r) temp[k++] = ara[j++];
    for(i = l, j = 0; i <= r; i++, j++)
        ara[i] = temp[j];
}
int main()
{
    int ara[] = {4, 40, 1, 0, 5, 3, 1};
    merge_sort(ara, 0, 6);
    for(int i = 0; i < 7; i++)
        cout<<ara[i]<<" ";
    return 0;
}
