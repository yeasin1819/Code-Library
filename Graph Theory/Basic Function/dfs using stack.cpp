  void dfs(int source)
    {
        stack<int> st;
        st.push(source);
        while(!st.empty())
        {
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
