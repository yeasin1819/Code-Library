void dfsTime(int source)
    {
        int parent[SIZE];
        bool taken[SIZE];
        for(int i = 0; i < vertex; i++)
        {
            parent[i] = i;
            taken[i] = false;
        }
        int t = 0;
        stack<int>st;
        st.push(source);

        while(!st.empty())
        {
            int u = st.top();
            if(visited[u])
            {
                // cout<<u<<endl;
                ft[u] = t++;
                low[parent[u]] = min(low[parent[u]], low[u]);
                st.pop();
                continue;
            }
            dt[u] = t++;
            low[u] = dt[u];
            int len = adj[u].size();
            //for(int i = 0; i < len; i++)
            for(int i = len - 1; i >= 0; i--)
            {
                int v = adj[u][i];
                if(!visited[v])
                {
                    st.push(v);
                    parent[v] = u;
                }
                if(parent[u] != v && visited[v]) low[u] = min(low[u], dt[v]);
            }
            visited[u] = true;
        }
    }
