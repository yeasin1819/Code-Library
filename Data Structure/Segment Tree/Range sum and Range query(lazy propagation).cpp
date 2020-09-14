#include <bits/stdc++.h>

#define SIZE 100000

using namespace std;

typedef struct segment_tree Tree;

struct segment_tree
{
    int s, p;
};

int arr[SIZE];
Tree tree[SIZE];;

void build(int at, int l, int r)
{
    if(l == r)
    {
        tree[at].s = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * at, l, mid);
    build(2 * at + 1, mid + 1, r);
    tree[at].s = tree[2 * at].s + tree[2 * at + 1].s;
}

void update(int at, int L, int R, int l, int r, int u)
{
    if(r < L || R < l) return;
    if(l <= L && R <= r)
    {
        tree[at].s = tree[at].s + (R - L + 1) * u;
        tree[at].p += u;
        return;
    }
    int mid = (L + R) / 2;
    update(2 * at, L, mid, l, r, u);
    update(2 * at + 1, mid + 1, R, l, r, u);
    tree[at].s = tree[2 * at].s + tree[2 * at + 1].s + (R - L + 1) * tree[at].p;
}

int query(int at, int c, int L, int R, int l, int r)
{
    if(r < L || R < l) return 0;
    if(l <= L && R <= r)
    {
        return tree[at].s + c;
    }
    int mid = (L + R) / 2;
    int x = query(2 * at, tree[at].p, L, mid, l, r);
    int y = query(2 * at + 1, tree[at].p, mid + 1, R, l, r);
    return x + y;
}

int main()
{
    int n = 4;
    for(int i = 1; i <= n; i++) arr[i] = i;
    build(1, 1, n);
    update(1, 1, n, 1, 2, 3);
    update(1, 1, n, 3, 4, 2);
    update(1, 1, n, 1, 3, 1);
    cout<<query(1, 0, 1, n, 2, 3)<<endl;

    return 0;
}
