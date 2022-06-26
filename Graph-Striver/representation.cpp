#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<int> adj[], int V)
{
    for (int i = 1; i < V + 1; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the no of vertex: \n";
    cin >> n;
    cout << "Enter no of edges: \n";
    cin >> m;
    vector<int> adj[n + 1]; // at every index you have a vector
    // So, for every vertex there is a vector associated to it which represents the other vertices it is connected to.
    cout << "Enter the graph: \n";

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    print_graph(adj, n);
    return 0;
}
