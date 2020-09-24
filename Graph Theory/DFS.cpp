#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
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

void dfs(int s)
{
    stack<int> st;

    st.push(s);

    while(!st.empty())
    {
        int t = st.top();
        if(!visited[t])
        {
            cout<<t<<endl;
            visited[t] = true;
        }
        st.pop();
        for(int i = 0; i < adj[t].size(); i++)
        {
            if(visited[adj[t][i]] == false)
            {
                st.push(adj[t][i]);
            }
        }
    }
}

int main()
{

    input_graph();

    for(int i = 0; i < vertex; i++)
        if(!visited[i]) dfs(i);

    return 0;
}
