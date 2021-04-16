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
