struct Graph
{
    int vertex, edge;
    vector<int>adj[SIZE];
    bool visited[SIZE] = {0};

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
    ~Graph()
    {
        for(int i = 0; i <= vertex; i++) adj[i].clear();
    }
};
