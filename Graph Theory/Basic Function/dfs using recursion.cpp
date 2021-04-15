 void dfs(int source)
    {
        visited[source] = true;
        cout<<source<<endl;
        int len = adj[source].size();
        for(int i = 0; i < len; i++)
        {
            int v = adj[source][i];
            if(!visited[v]) dfs(v);
        }
    }
