#include <bits/stdc++.h>

#define SIZE 100000

using namespace std;

typedef struct product Product;

struct product
{
    double weight, profit;
};

void merge_sort(Product p[], int l, int r)
{
    if(r <= l) return;
    int mid = (r + l) / 2;
    merge_sort(p, l, mid);
    merge_sort(p, mid + 1, r);
    Product temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while((i <= mid) && (j <= r))
    {
        if(p[i].profit < p[j].profit) temp[k++] = p[j++];
        else temp[k++] = p[i++];
    }
    while(i <= mid) temp[k++] = p[i++];
    while(j <= r) temp[k++] = p[j++];
    for(i = l, k = 0; i <= r; i++, k++) p[i] = temp[k];
}

int main()
{
    /*Input:
    n = 7, m = 15
    Objects:  1  2 3  4 5  6  7
    Profits: 12  5 16 7 9 11  6
    Weights: 3   1 4  2 9  4  3
    Output: 53
    */
    double n, m, res = 0.0;
    Product p[SIZE];

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>p[i].weight>>p[i].profit;
        p[i].profit = p[i].profit / p[i].weight;// profit for per weight.
    }
    merge_sort(p, 0, n - 1);
    for(int i = 0; i < n && m > 0; i++)
    {
        res = res + min(p[i].weight, m) * p[i].profit;
        m -= p[i].weight;
    }
    cout<<res<<endl;
    return 0;
}
