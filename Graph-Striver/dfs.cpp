#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfsTraverse(vector<int> g[], vector<int> *v, int visit[], int n, int i)
{
    if (visit[i] == 0)
        v->push_back(i);
    visit[i] = 1;
    for (auto it = g[i].begin(); it != g[i].end(); it++)
    {
        if (visit[*it] == 0)
            dfsTraverse(g, v, visit, n, *it);
    }
}

vector<int> dfs(vector<int> g[], int N)
{

    // Your code here
    vector<int> vec;
    int visit[N] = {0};
    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            dfsTraverse(g, &vec, visit, N, 0);
        }
    }

    return vec;
}

// { Driver Code Starts.

int main()
{
    cout << "Enter no of vertex and edge: \n";
    int N, E;
    cin >> N >> E;

    vector<int> g[N];
    bool vis[N];

    memset(vis, false, sizeof(vis));
    cout << "Enter the graph: \n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> res = dfs(g, N);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
} // } Driver Code Ends