#include <bits/stdc++.h>

using namespace std;

#define SIZE 3001

struct Graph
{
    int vertex, edge, tm = 1, dt[SIZE], low[SIZE], ft[SIZE];
    vector<int>adj[SIZE], ap;
    bool visited[SIZE];

    Graph(int v, int e)
    {
        vertex = v;
        edge = e;
        memset(visited, false, sizeof(bool) * SIZE);
    }
    void getAdjList()
    {
        for(int i = 0; i < edge; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void dfsForAp(int source, int parent)
    {
        visited[source] = true;
        low[source] = dt[source] = tm++;
        int child = 0, len = adj[source].size();
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            int v = adj[source][i];
            if(visited[v] && v != parent) low[source] = min(low[source], dt[v]);//This is Back edge
            else if(visited[v] && v == parent) child++;
            else//or else if(!visited[v])
            {
                dfsForAp(v, source);/*Here, 'v' is Converted to 'source' and 'source' is parent of v*/
                low[source] = min(low[source], low[v]);
                child++;
                if(dt[source] <= low[v]) flag = true;
            }
        }
        if(flag && child > 1) ap.push_back(source);
        tm++;
    }
    ~Graph()
    {
        for(int i = 0; i <= vertex; i++) adj[i].clear();
    }
};

void solve()
{
    int v, e;
    cin>>v>>e;
    Graph g(v, e);
    g.getAdjList();
    g.dfsForAp(0, 0);
    cout<<"Total: "<<g.ap.size()<<endl;
    for(int i = 0; i < g.ap.size(); i++) cout<<g.ap[i]<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin>>t; while(t--) solve();
    //int i = 1; while(i <= t) cout<<"Case "<<i++<<": "<<endl, solve();
    solve();
/*Sample Input:
7 6//7 is vertex, 6 is number of edge
0 1
1 2
3 4
2 4
2 6
5 2
Output:

*/

    return 0;
}
