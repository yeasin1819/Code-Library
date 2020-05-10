#include <bits/stdc++.h>

using namespace std;

struct pair_data
{
    int x, y;
};

typedef struct pair_data pd;

void merge_sort(pd ara[], int l, int r)
{
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(ara, l, mid);
    merge_sort(ara, mid + 1, r);
    pd temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while((i <= mid) && (j <= r))
    {
        if((ara[i].x <= ara[j].x) && (ara[i].y <= ara[j].y)) temp[k++] = ara[i++];
        else temp[k++] = ara[j++];
    }
    while(i <= mid) temp[k++] = ara[i++];
    while(j <= r) temp[k++] = ara[j++];
    for(i = l, k = 0; i <= r; i++, k++) ara[i] = temp[k];
}
int main()
{
    pd input[200];
    input[0].x = 1, input[1].x = 5, input[2].x = 2, input[3].x = 1;
    input[0].y = 4, input[1].y = 8, input[2].y = 1, input[3].y = 4;
    merge_sort(input, 0, 3);
    for(int i = 0; i < 4; i++) cout<<input[i].x<<" "<<input[i].y<<endl;
    return 0;
}
