#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int ara[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i, k = i - 1;
        while(ara[j] < ara[k] && k >= 0)
        {
            int temp = ara[j];
            ara[j] = ara[k];
            ara[k] = temp;
            j--;
            k--;
        }
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
