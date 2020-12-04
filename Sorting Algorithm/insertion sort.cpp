#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int ara[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1, x = ara[i];
        while(j >= 0 && ara[j] > x)
        {
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = x;
    }
}
int main()
{
    int ara[] = {100, 10, 50, 2, 90, 0};
    insertion_sort(ara, 6);
    for(int i = 0; i < 6; i++)
        cout<<ara[i]<<" ";
    return 0;
}
