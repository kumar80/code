
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i = j; i < k; i++)

class Graph
{
    int V;
    int ans = 0;
    list<int> *adj;

    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    int connectedComponents();
};

int Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            DFSUtil(v, visited);
            ans++;
        }
    }
    delete[] visited;
    return ans;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    int n;
    cin >> n;
    Graph g(n);

    FOR(i, 0, n)
    FOR(j, 0, n)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            g.addEdge(i, j);
        }
    }
    cout << g.connectedComponents();
    return 0;
}
