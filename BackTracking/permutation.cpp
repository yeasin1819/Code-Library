#include <bits/stdc++.h>

using namespace std;

void permutation(int ara[], int start, int end)
{
    if(start == end)
    {
        for(int i = 0; i <= end; i++)
            cout<<ara[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = start; i <= end; i++)
    {
        swap(ara[start], ara[i]);
        permutation(ara, start + 1, end);
        swap(ara[start], ara[i]);
    }
}

int main()
{
    int ara[] = {1, 2, 3};
    permutation(ara, 0, 2);
    return 0;
}
