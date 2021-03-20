/*Accepted, Submission Link: https://www.hackerearth.com/submission/55366709/ */
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int numOfNodes, numOfEdges;
    vector< vector<int> > adjList;

    void getAdjList()
    {
        cin>>numOfNodes>>numOfEdges;
        adjList.resize(numOfNodes + 1);
        for(int i  = 1; i <= numOfNodes; i++)
            adjList[i].resize(numOfNodes + 1);
        for(int i = 0; i < numOfEdges; i++)
        {
            int u, v;
            cin>>u>>v;
            adjList[u][v] = 1;
        }
    }
    void topSort()
    {
       priority_queue<int, vector<int>, greater<int> > q;
        int inDeg[numOfNodes + 1] = {0};
        bool visited[numOfNodes + 1] = {false};
        //Count Indegree of All Nodes
        for(int i = 1; i <= numOfNodes; i++)
            for(int j = 1; j <= numOfNodes; j++)
                inDeg[j] += adjList[i][j];
        //Find a node that Indegree is zero
        for(int i = 1; i <= numOfNodes; i++)
            if(!inDeg[i]) q.push(i), visited[i] = true;
        while(!q.empty())
        {
            int node = q.top();
            cout<<node<<" ";
            q.pop();
            for(int i = 1; i <= numOfNodes; i++)
            {
                if(adjList[node][i])
                {
                    inDeg[i]--;
                    if(!visited[i] && !inDeg[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
};


int main()
{
    //freopen("input.txt", "r", stdin);
    Graph g;

    g.getAdjList();
    g.topSort();

    return 0;
}
