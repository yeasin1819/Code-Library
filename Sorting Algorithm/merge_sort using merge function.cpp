#include <bits/stdc++.h>

using namespace std;

void merge(int ara[], int l, int mid, int r)
{
    int SIZE = r - l + 1;
    int temp[SIZE], k = 0, i= l, j = mid+1;
    while((i <= mid) && (j <= r))
    {
        if(ara[i] < ara[j] && (i <= mid)) temp[k++] = ara[i++];
        else temp[k++] = ara[j++];
    }
    while(i <= mid) temp[k++] = ara[i++];
    while(j <= r) temp[k++] = ara[j++];
    for(int i = l, j = 0; i <= r; i++, j++)
        ara[i] = temp[j];
}
void merge_sort(int ara[], int l, int r)
{
    if(l == r) return;
    int mid = (l + r) / 2;
    merge_sort(ara, l, mid);
    merge_sort(ara, mid + 1, r);
    merge(ara, l, mid, r);
}
int main()
{
    int ara[] = {40, 4, 6, 5, 4, 1, 3};
    merge_sort(ara, 0, 6);
    for(int i = 0; i < 7; i++)
        cout<<ara[i]<<" ";
    return 0;
}
