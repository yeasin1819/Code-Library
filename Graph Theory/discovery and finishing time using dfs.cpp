#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int vertex, edge, u, v, len;
vector<bool>visited;
vector<int> dt, ft;
vector< vector<int> > adjList;

void getAdjList()
{
    cin>>vertex>>edge;
    adjList.resize(vertex + 1);
    dt.resize(vertex + 1);
    ft.resize(vertex + 1);
    visited.resize(vertex + 1, false);
    for(int i = 0; i < edge; i++)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
       // adjList[v].push_back(u);
    }
}

void dfsTime(int source)
{
    int t = 1;
    stack<int>st;
    st.push(source);

    while(!st.empty())
    {
        u = st.top();
        if(visited[u])
        {
            ft[u] = t++;
            st.pop();
            continue;
        }
        dt[u] = t++;
        len = adjList[u].size();
        //for(int i = 0; i < len; i++)
        for(int i = len - 1; i >= 0; i--)
        {
            v = adjList[u][i];
            if(!visited[v]) st.push(v);
        }
        visited[u] = true;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    getAdjList();
    dfsTime(1);
    for(int i = 1; i <= vertex; i++) cout<<i<<" "<<dt[i]<<" / "<<ft[i]<<endl;

    return 0;
}
