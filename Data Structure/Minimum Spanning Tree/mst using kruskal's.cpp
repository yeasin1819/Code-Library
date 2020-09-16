#include <bits/stdc++.h>

#define SIZE 1000

using namespace std;

typedef struct graph Graph;

struct graph
{
    int u, v, w;
};

Graph g[SIZE];

int edge, p[SIZE];

bool cmp(Graph a, Graph b)
{
    return a.w < b.w;
}

void input_graph()
{
    cin>>edge;
    for(int i = 0; i < edge; i++) cin>>g[i].u>>g[i].v>>g[i].w;
}

void print_graph()
{
    for(int i = 0; i < edge; i++)
    {
        cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
    }
}

int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int u, int v)
{
    p[Find(v)] = Find(u);
}
int kruskal()
{
    int s = 0;
    for(int i = 0; i < edge; i++)
    {
        if(Find(g[i].u) != Find(g[i].v))
        {
            s += g[i].w;
            Union(g[i].u, g[i].v);
        }
    }
    return s;
}

int main()
{
    /*
    8
    1 2 5
    1 3 8
    1 4 4
    1 5 7
    2 6 2
    3 4 2
    3 5 3
    4 6 3
    */
    for(int i = 0; i < SIZE; i++) p[i] = i;
    input_graph();
    sort(g, g + edge, cmp);
    print_graph();
    cout<<endl;
    cout<<kruskal()<<endl;

    return 0;
}
