/*Accepted, Submission Link: https://www.hackerearth.com/submission/55245582/ */
#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int vertex, cost;
    node(int v, int c)
    {
        vertex = v;
        cost = c;
    }
};

struct cmp
{
    bool operator()(const Node &a, const Node &b) const
    {
        return a.cost > b.cost;
    }
};

class Graph
{
public:
    vector<vector<Node> > adjList;
    int numOfNodes, numOfEdges;
    void getAdjList()
    {

        cin>>numOfNodes>>numOfEdges;
        adjList.resize(numOfNodes + 1);
        for(int i = 0; i < numOfEdges; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            adjList[u].push_back(Node(v, w));
            adjList[v].push_back(Node(u, w));
        }
    }
};

long long prims(Graph g)
{
    priority_queue<Node, vector<Node>, cmp> pq;

    long long ans = 0;
    bool taken[g.numOfNodes + 1];
    for(int i = 1; i <= g.numOfNodes; i++) taken[i] = false;
    pq.push(Node(1, 0));

    while(!pq.empty())
    {
        Node node = pq.top();
        pq.pop();
        if(taken[node.vertex]) continue;
        ans += node.cost;
        taken[node.vertex] = true;

        for(int i = 0; i < g.adjList[node.vertex].size(); i++)
            if(!taken[g.adjList[node.vertex][i].vertex])pq.push(g.adjList[node.vertex][i]);
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    Graph g;

    g.getAdjList();

    cout<<prims(g)<<endl;

    return 0;
}
