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
                if(dt[root] <= low[u] && child[root]>1 && u != root && !taken[root])
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
