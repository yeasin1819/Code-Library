void dfsTime(int source)
    {
        cout<<source<<" ";
        dt[source] = tm++;
        visited[source] = true;
        int len = adj[source].size();
        for(int i = 0; i < len; i++)
        {
            int v = adj[source][i];
            if(!visited[v]) dfsTime(v);
        }
        ft[source] = tm++;
    }
