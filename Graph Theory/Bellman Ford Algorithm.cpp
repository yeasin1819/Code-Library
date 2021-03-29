/*Accepted, Submission Link: https://www.hackerearth.com/submission/55766272/ */
#include <bits/stdc++.h>
#define INF 100000000

using namespace std;
typedef struct node Node;

struct node
{
    int vertex, cost;
};

int node, edge, u, v, cost;
vector< vector<Node> > adjList;

void inputGraph()
{
    cin>>node>>edge;
    adjList.resize(node + 1);

    for(int i = 0; i < edge; i++)
    {
        cin>>u>>v>>cost;
        adjList[u].push_back({v, cost});
    }
}

void bellMan()
{

    int distance[node + 1];
    for(int i = 1; i <= node; i++) distance[i] = INF;

    int n = node;
    while(n--)
    {
        queue<Node> q;

        distance[1] = 0;
        q.push({1, 0});

        while(!q.empty())
        {
            u = q.front().vertex;
            q.pop();
            for(int i = 0; i < adjList[u].size(); i++)
            {
                v = adjList[u][i].vertex;
                cost = adjList[u][i].cost;
                if(distance[u] + cost < distance[v])
                {
                    distance[v] = distance[u] + cost;
                    q.push({v, cost});
                }

            }
        }
    }
   for(int i = 2; i <= node; i++)
    cout<<distance[i]<<" ";
   cout<<endl;

}

int main()
{
    //freopen("input.txt", "r", stdin);
    inputGraph();

    bellMan();

    return 0;
}
