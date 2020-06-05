#include <bits/stdc++.h>

#define M 1000000000

using namespace std;

int ncr[1001][1001];///Limit r <= n <= 1000

void solve()
{
    for(int i = 0; i < 1001; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(i == j) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i-1][j-1] % M + ncr[i-1][j] % M) % M;
        }
    }
}


int main()
{
    solve();
    int t, n, r;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        cout<<ncr[n][r]<<endl;
    }

    return 0;
}
