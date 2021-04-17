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
