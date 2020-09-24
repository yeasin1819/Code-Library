#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100];
bool visited[100] = {false};
int edge, vertex;

void input_graph()
{
    int a, b;
    cout<<"Enter the number of edge: ";
    cin>>edge;
    cout<<"Enter the number of vertex: ";
    cin>>vertex;
    for(int i = 0; i < edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;

    q.push(s);

    while(!q.empty())
    {
        int a = q.front();
        cout<<a<<endl;
        q.pop();
        for(int i = 0; i < adj[a].size(); i++)
        {
            if(visited[adj[a][i]] == false)
            {
                q.push(adj[a][i]);
                visited[adj[a][i]] = true;
            }
        }
    }
}

int main()
{
    input_graph();
    /*
    edge = 8.
    vertex = 7
    1 2
    1 5
    2 3
    2 5
    5 4
    3 4
    4 6
    7 7
    */
    for(int i = 1; i <= vertex; i++) if(visited[i] == false) bfs(i);

    return 0;
}
