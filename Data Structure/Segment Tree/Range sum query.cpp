#include <bits/stdc++.h>

#define SIZE 100000

using namespace std;

int arr[SIZE], tree[SIZE];

void build(int at, int L, int R)
{
    if(L == R)
    {
        tree[at] = arr[L];
        return;
    }
    int mid = (R + L) / 2;
    build(2 * at, L, mid);
    build(2 * at + 1, mid + 1, R);
    tree[at] = tree[2 * at] + tree[2 * at + 1];
}

void update(int at, int L, int R, int pos, int u)
{
    if(pos < L || R < pos) return;
    if(L == R)
    {
        tree[at] = u; //arr[at] += u;
        return;
    }
    int mid = (L + R) / 2;
    if(pos <= mid) update(2 * at, L, mid, pos, u);
    else update(2 * at + 1, mid + 1, R, pos, u);
    tree[at] = tree[2 * at] + tree[2 * at + 1];
}

int query(int at, int L, int R, int l, int r)
{
    if(r < L || R < l) return 0;
    if(l <= L && R <= r) return tree[at];
    int mid = (L + R) / 2;
    int x = query(2 * at, L, mid, l, r);
    int y = query(2 * at + 1, mid + 1, R, l, r);
    return x + y;
}

int main()
{
    int n = 5;
    for(int i = 1; i <= n; i++) arr[i] = i;

    build(1, 1, n);
    update(1, 1, n, 2, 3);
    cout<<query(1, 1, n, 1, 5)<<endl;

    return 0;
}
