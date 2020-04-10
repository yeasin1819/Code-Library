#include <bits/stdc++.h>

using namespace std;

void buble_sort(int ara[], int n)
{
    while(1)
    {
        int flag = 0;
        for(int i = 0; i < n - 1; i++)
        {
             if(ara[i] > ara[i+1])
             {
                 swap(ara[i], ara[i+1]);
                 flag = 1;
             }
        }
        if(!flag) break;
    }
}

int main()
{
    int ara[] = {10, -1, -2, 50, 40};
    buble_sort(ara, 5);
    for(int i = 0; i < 5; i++)
        cout<<ara[i]<<" ";
    return 0;
}
