#include <bits/stdc++.h>

using namespace std;

void two_pointer(int ara[], int n, int x)
{
    int i = 0, j = n - 1;
    while(i < j)
    {
        if(ara[i] + ara[j] == x) cout<<ara[i]<<" "<<ara[j]<<" "<<x<<endl;
        if(ara[i] + ara[j] > x) j--;
        else i++;
    }
}
int main()
{
    int ara[] = {5, 10, 20, 35, 50, 65, 80};
    two_pointer(ara, 7, 70);
    return 0;
}
