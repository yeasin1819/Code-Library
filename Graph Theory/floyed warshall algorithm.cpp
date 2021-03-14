/*Accepted, Submission link: https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/submissions/code/204188137 */
#include <bits/stdc++.h>
#define INF 100000

using namespace std;
typedef vector< vector<int> > vector2D;

class Graph
{
public:
    int numOfNodes, numOfEdges;
    vector2D adjMat;
    void getAdjMat()
    {
        cin>>numOfNodes>>numOfEdges;
        adjMat.resize(numOfNodes + 1);
        for(int i = 1; i <= numOfNodes; i++)
            adjMat[i].resize(numOfNodes + 1, INF);

        for(int j = 1; j <= numOfEdges; j++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            adjMat[u][v] = w;
        }
    }
};

vector2D floyedWarshall(Graph g)
{
    vector2D dist = g.adjMat;
    for(int k = 1; k <= g.numOfNodes; k++)
        for(int i = 1; i <= g.numOfNodes; i++)
            for(int j = 1; j <= g.numOfNodes; j++)
              i != j ? dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) : dist[i][j] = 0;
    return dist;
}

int main()
{
    Graph g;

    g.getAdjMat();
    vector2D dist = floyedWarshall(g);

    int q, u, v;
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        dist[u][v] != INF ? cout<<dist[u][v]<<endl : cout<<"-1"<<endl;
    }
    return 0;
    /*Sample input:
4 5
1 2 5
1 4 24
2 4 6
3 4 4
3 2 7
3
1 2
3 1
1 4
Sample Output:
5
-1
11
*/
}
