#include <bits/stdc++.h>

#define SIZE 10000

using namespace std;

int arr[SIZE];

void update(int idx, int n, int v)
{
   while(idx <= n)
   {
       arr[idx] += v;
       idx += (idx & -idx);
   }
}
int query(int idx)
{
    int s = 0;
    while(idx)
    {
        s += arr[idx];
        idx -= (idx & -idx);
    }
    return s;
}

int main()
{
    int n = 4;
    for(int i = 1; i <= n; i++) update(i, n, i);

    cout<<query(4)<<endl;
    return 0;
}
