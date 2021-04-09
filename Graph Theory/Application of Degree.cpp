/*Accepted, Submission Link: https://toph.co/p/itsy-s-magic-cards */
#include <bits/stdc++.h>

using namespace std;

int findMax(int arr[], int n)
{
    int idx = 0;
    for(int i = 1; i <= n; i++)
        if(arr[idx] < arr[i]) idx = i;
    return idx;
}

void solve()
{
    bool adjMat[18][18];
    for(int i = 0; i < 18; i++)
    {

        for(int j =  0; j < 18; j++)
        {
            adjMat[i][j] = false;
            adjMat[j][i] = false;
        }
    }
    int n, m, ans = 0, deg[18] = {0};
    char u, v;

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>u>>v;
        adjMat[u - 64][v - 64] = true;
        adjMat[v - 64][u - 64] = true;
        deg[u - 64]++;
        deg[v - 64]++;
    }

    for(int i = 1; i <= n; i++)
    {
        int idx = findMax(deg, n);
        if(deg[idx] == 0) break;
        for(int j = 1; j <= n; j++)
        {
            if(adjMat[idx][j])
            {
                adjMat[idx][j] = false;
                deg[j]--;
            }
        }
        deg[idx] = -1;
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) ans++;
    cout<<ans<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin>>t;
    //int i = 1; while(i <= t) cout<<"Case "<<i++<<": "<<endl, solve();
    //while(t--)
    solve();

    return 0;
}
