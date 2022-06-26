#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int V)
{
    vector<bool> vis(V + 1, false);
    for (int i = 1; i < V + 1; i++)
    { // this loop is just to ensure that whole graph (all connected components) are printed
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                vis[node] = true;
                cout << node << " ";
                for (auto x : adj[node])
                {
                    if (!vis[x])
                    {
                        q.push(x);
                        vis[x] = true;
                    }
                }
            }
        }
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
    bfs(adj, n);
    return 0;
}