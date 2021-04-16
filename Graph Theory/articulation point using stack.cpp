#include <bits/stdc++.h>

using namespace std;

#define SIZE 3001

struct Graph
{
    int vertex, edge, parent[SIZE], child[SIZE], dt[SIZE], low[SIZE];
    vector<int>adj[SIZE], ap;
    bool visited[SIZE], taken[SIZE];

    Graph(int v, int e)
    {
        vertex = v;
        edge = e;
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
    void dfsForAp(int source)
    {
        for(int i = 0; i <= vertex; i++)
        {
            parent[i] = i;
            visited[i] = false;
            child[i] = 0;
            taken[i] = false;
        }
        int tm = 1;
        stack<int> st;
        st.push(source);
        while(!st.empty())
        {
            int u = st.top();

            if(visited[u])
            {
                int root = parent[u];
                low[root] = min(low[u], low[root]);
                if(u != root) child[root]++;
                if(dt[root] <= low[u] && child[root] > 1 && u != root && !taken[root])
                {
                    ap.push_back(root);
                    taken[root] = true;
                }
                st.pop();
                continue;
            }
            low[u] = dt[u] = tm++;
            int v, len = adj[u].size();
            if(u != parent[u]) child[u]++;
            for(int i = len - 1; i >= 0; i--)
            {
                v = adj[u][i];
                if(!visited[v])
                {
                    st.push(v);
                    parent[v] = u;
                }
                else if(visited[v] && parent[u] != v)//Back edge found
                low[u] = min(low[u], dt[v]);
            }
            visited[u] = true;
        }
    }
    ~Graph()
    {
        for(int i = 0; i <= vertex; i++) adj[i].clear();
    }
};

void solve()
{
    int v, e, k;
    cin>>v>>e>>k;
    Graph g(v, e);
    g.getAdjList();
    g.dfsForAp(0);
    cout<<g.ap.size() * k<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; cin>>t; while(t--) solve();
    //int i = 1; while(i <= t) cout<<"Case "<<i++<<": "<<endl, solve();
    // solve();

    return 0;
}

