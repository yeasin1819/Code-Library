#include <bits/stdc++.h>

using namespace std;

int b_search(int ara[], int n, int v)
{
    int l = 0, r = n - 1, mid;
    while(r >= l)
    {
        mid = l + (r - l) / 2;
        if(ara[mid] == v) return mid;
        else if(ara[mid] < v) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main()
{
    int ara[] = {1, 4, 5, 6, 7, 9};
    int v = 4;
    int idx = b_search(ara, 6, v);
    if(idx >= 0) cout<<idx<<" is position of "<<v<<endl;
    else cout<<v<<" is not found"<<endl;
    return 0;
}
