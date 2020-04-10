#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int ara[], int n)
{
    for(int i = 1; i < n; i++)
    {
       for(int j = 0; ara[i] < ara[j]; j++)
               swap(ara[j], ara[i]);
    }
}
int main()
{
    int ara[] = {10, 2, 0, -1, 10, -2, 100};
    insertion_sort(ara, 7);
    for(int i = 0; i < 7; i++)
        cout<<ara[i]<<" ";
    return 0;
}
