/*Accepted, Submission Link: https://lightoj.com/problem/critical-links */
#include <bits/stdc++.h>

#define SIZE 10001

using namespace std;

struct Edge
{
    int u, v;
    void print()
    {
        cout<<u<<" - "<<v<<endl;
    }
};

struct cmp
{
    bool operator() (Edge &a, Edge &b)
    {
        if(a.v < a.u) swap(a.u, a.v);
        if(b.v < b.u) swap(b.u, b.v);
        if(a.u == b.u) return a.v < b.v;
        return a.u < b.u;
    }
};

struct Graph
{
    int vertex, low[SIZE], dt[SIZE], tm = 1;
    vector<int>adj[SIZE];
    vector<Edge> bridge;
    bool visited[SIZE];

    Graph(int v)
    {
        vertex = v;
        memset(visited, false, sizeof(bool) * SIZE);
    }
    void getAdjList()
    {
        int node, edge = 0, v;
        string str;
        for(int i = 0; i < vertex; i++)
        {
            cin>>node;
            cin>>str;
            str.erase(str.begin());
            str.erase(str.begin() + str.length() - 1);
            stringstream st(str);
            st>>edge;
            while(edge--)
            {
                cin>>v;
                adj[node].push_back(v);
                adj[v].push_back(node);
            }
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
                //if(dt[source] <= low[v]) flag = true;
                if(dt[source] < low[v]) bridge.push_back({source, v});
            }
        }
       // if(flag && child > 1) ap.push_back(source);
        tm++;
    }
    ~Graph()
    {
        for(int i = 0; i <= vertex; i++) adj[i].clear();
    }
};

void solve()
{
    int v;
    cin>>v;
    Graph g(v);
    g.getAdjList();
    for(int i = 0; i < v; i++) if(!g.visited[i])g.dfs(i, i);
    sort(g.bridge.begin(), g.bridge.end(), cmp());
    cout<<g.bridge.size()<<" critical links"<<endl;
    for(int i = 0; i < g.bridge.size(); i++) g.bridge[i].print();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin>>t; while(t--) solve();
    int t; cin>>t; int i = 1; while(i <= t) cout<<"Case "<<i++<<":"<<endl, solve();
    //solve();
    return 0;
}
