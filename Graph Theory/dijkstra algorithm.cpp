/*Accepted: submission link//https://www.hackerearth.com/submission/55014460/*/

#include <bits/stdc++.h>
#define INF 1000000000

typedef struct node Node;
typedef struct edge Edge;

using namespace std;

struct node
{
    int vertex, cost;
};
struct edge
{
    int u, v, w;
};

struct cmp
{
    bool operator ()(const Node &a, const Node &b) const
    {
        return a.cost > b.cost;
    }
};

class Graph
{
public:
    vector< vector<Edge> > adjList;
    int numOfEdges, numOfNodes;
    void getAdjList()
    {
        int u, v, w;
        cin>>numOfNodes>>numOfEdges;
        adjList.resize(numOfNodes + 1);
        for(int i = 1; i <= numOfEdges; i++)
        {
            cin>>u>>v>>w;
            adjList[u].push_back({u, v, w});
        }
    }
};

void dijkastra(int source, Graph g)
{
    int dist[g.numOfNodes + 1];
    priority_queue<Node, vector<Node>, cmp> pq;

    for(int i = 0; i < g.numOfNodes + 1; i++) dist[i] = INF;
    pq.push({source, 0});
    dist[source] = 0;

    while(!pq.empty())
    {
        int u = pq.top().vertex;
        pq.pop();
        for(int i = 0; i < g.adjList[u].size(); i++)
        {
            Edge e = g.adjList[u][i];
            if(dist[e.v] > dist[u] + e.w)
            {
                dist[e.v] = dist[u] + e.w;
                pq.push({e.v, dist[e.v]});
            }
        }
    }
    for(int i = 2; i <= g.numOfNodes; i++)
       cout<<dist[i]<<" ";
       cout<<endl;
}

int main()
{
    Graph g;
    g.getAdjList();
    dijkastra(1, g);
/*
Sample Input:
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5
Sample Output:
5 2 3 7
*/
}
