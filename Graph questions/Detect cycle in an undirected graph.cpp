// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


  public:
  bool dfs(int src, int parent, vector<int> adj[], vector<bool> &visited){
      visited[src] = true;
      for (auto u : adj[src]){
          if(!visited[u]){
              if(dfs(u,src,adj,visited)){     // if not visited do dfs for the adj nodes
                  return true;
              }
          }
          else if(u != parent){       // if it is vistied check if it is the parent node. If not then cycle exists. 
              return true;
          }
      }
      return false;     // Because, in acyclic graph, a node will always have only one visited neighbour which will be its parent node
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for (int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, -1 , adj, visited)) // parent : -1 for first node
                    return true;
            }
        }
        return false;
    }
