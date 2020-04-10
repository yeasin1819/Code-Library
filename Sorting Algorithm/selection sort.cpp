#include <bits/stdc++.h>

using namespace std;

void selection_sort(int ara[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
            if(ara[i] > ara[j]) swap(ara[i], ara[j]);
    }
}
int main()
{
    int ara[] = {5, 10, 0, -2, 10};
    selection_sort(ara, 5);
    for(int i = 0; i < 5; i++)
        cout<<ara[i]<<" ";
    return 0;
}
