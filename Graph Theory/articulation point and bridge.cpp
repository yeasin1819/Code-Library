#include <bits/stdc++.h>
/*
#define SIZE 100

using namespace std;

struct Edge
{
    int u, v;
    void print()
    {
    cout<<u<<" "<<v<<endl;
    }
};

struct cmp
{
    bool operator() (Edge &a, Edge &b)
    {
        if(a.v < a.u) swap(a.u, a.v);
        if(b.v < a.u) swap(a.u, a.v);
        if(a.u < b.u) return true;
        if(a.v < b.v) return true;
        return false;
    }
};

struct Graph
{
    int vertex, edge, tm = 1, dt[SIZE], low[SIZE];
    vector<int>adj[SIZE], ap;
    bool visited[SIZE];
    vector<Edge>bridge;

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
    void dfs(int source, int parent)
    {
        visited[source] = true;
        int child = 0;
        low[source] = dt[source] = tm++;
        int len = adj[source].size();
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            int v = adj[source][i];
            if(visited[v] && parent != v)//Back Edge Found
            {
                low[source] = min(low[source], dt[v]);
            }
            else if(visited[v] && parent == v) child++;
            else if(!visited[v])
            {
                dfs(v, source);
                child++;
                low[source] = min(low[source], low[v]);
                if(dt[source] <= low[v]) flag = true;
                if(dt[source] < low[v]) bridge.push_back({source, v});
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
    g.dfs(0, 0);
    sort(g.ap.begin(), g.ap.end());
    sort(g.bridge.begin(), g.bridge.end(), cmp());
    cout<<g.ap.size()<<endl;
    for(int i = 0; i < g.ap.size(); i++) cout<<g.ap[i]<<" ";
    cout<<endl;
    cout<<g.bridge.size()<<endl;
    for(int i = 0; i < g.bridge.size(); i++) g.bridge[i].print();
    cout<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin>>t; while(t--) solve();
    //int i = 1; while(i <= t) cout<<"Case "<<i++<<": "<<endl, solve();
    solve();

    return 0;
}
*/
