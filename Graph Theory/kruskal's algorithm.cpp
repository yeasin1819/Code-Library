/*Accepted, Submission Link: https://www.hackerearth.com/submission/55263812/ */
#include <bits/stdc++.h>

using namespace std;
typedef struct edge Edge;

struct edge
{
    int u, v, w;
};

struct cmp
{
    bool operator()(const Edge &a, const Edge &b) const
    {
        return a.w < b.w;
    }
};

class Graph
{
    public:
    int numOfNodes, numOfEdges, *parent;
    vector<Edge>edges;
    void getEdges()
    {
        cin>>numOfNodes>>numOfEdges;
        edges.resize(numOfEdges);
        for(int i = 0; i < numOfEdges; i++)
            cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    //Implementation of Disjoint set Union DS Start Here
    void setParent()
    {
       parent = (int*)malloc(sizeof(int) * (numOfNodes + 1));
       for(int i = 1; i <= numOfNodes; i++) parent[i] = i;
    }
    int findParent(int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void Union(int a, int b)
    {
       parent[findParent(b)] = findParent(a);
    }
    //Disjoint Set Union DS End.
    int kruskals()
    {

        int ans = 0;
        setParent();

        sort(edges.begin(), edges.end(), cmp());

        for(int i = 0; i < edges.size(); i++)
        {
            if(findParent(edges[i].u) != findParent(edges[i].v))
                ans += edges[i].w, Union(findParent(edges[i].u) , findParent(edges[i].v));
        }
        free(parent);
        return ans;
    }

};

int main()
{
   // freopen("input.txt", "r", stdin);
    Graph g;

    g.getEdges();

    cout<<g.kruskals()<<endl;

    return 0;
}
