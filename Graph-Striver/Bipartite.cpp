class Solution {
public:
    
    bool bipartiteDFS(int node, vector<vector<int>>& graph,vector<int> &color){
        if (color[node] == -1) //first node to be colored with color 1
            color[node] = 1;
        for (auto x : graph[node]){
            if (color[x] == -1){
                color[x] = 1 - color[node];     //if unvisited color it with opposite color to its parent node
                if(!bipartiteDFS(x,graph,color)){
                    return false;     //if fails at any point return false
                }
            }
            else if(color[x] == color[node]){     //if color of curr node and its parent matches means not bipartite
                return false;
            }
        }
        return true;    //if none of the cases generate false its a bipartite graph
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for (int i=0; i<graph.size(); i++){
            if(color[i] == -1){
                if (!bipartiteDFS(i,graph,color))
                    return false;
            }
        }
        return true;
    }
};
