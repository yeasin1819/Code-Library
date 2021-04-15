void dfs(int source)
    {
        stack<int> st;
        st.push(source);
        while(!st.empty())
        {
            int u = st.top();
            if(visited[u])
            {
                //cout<<u<<" ";
                st.pop();
                continue;
            }
            int v, len = adj[u].size();
            for(int i = len - 1; i >= 0; i--)
            {
                v = adj[u][i];
                if(!visited[v]) st.push(v);
            }
            visited[u] = true;
        }
    }
