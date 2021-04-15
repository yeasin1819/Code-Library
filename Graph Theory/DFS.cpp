/*Accepted, Submission Link: https://www.codechef.com/viewsolution/44978282 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001

struct Graph
{
    int vertex, edge, cnt;
    vector<int>adj[SIZE];
    bool visited[SIZE];

    Graph(int v, int e)
    {
        vertex = v;
        edge = e;
        memset(visited, false, sizeof(bool) * SIZE);
        cnt = 0;
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
    void dfs(int source)
    {
        stack<int> st;
        st.push(source);
        while(!st.empty())
        {
            cnt++;
            int u = st.top();
            st.pop();
            if(!visited[u])
            {
                //cout<<u<<" ";
                visited[u] = true;
            }
            int v, len = adj[u].size();
            for(int i = len - 1; i >= 0; i--)
            {
                v = adj[u][i];
                if(!visited[v]) st.push(v);
            }
        }
    }
    ~Graph()
    {
        for(int i = 0; i <= vertex; i++) adj[i].clear();
    }
};

void solve()
{
    int v, e, ans = 0;
    cin>>v>>e;
    Graph g(v, e);
    g.getAdjList();
    for(int i = 0; i < v; i++)
        if(!g.visited[i]) g.dfs(i), ans++;
    cout<<ans<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; cin>>t; while(t--) solve();
    //int i = 1; while(i <= t) cout<<"Case "<<i++<<": "<<endl, solve();
    // solve();

    return 0;
}
