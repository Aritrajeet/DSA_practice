    //dfs solution
    unordered_map<Node*, Node*> new_graph;  //key: original node and value: copy of node
    Node* cloneGraph(Node* node) {
        if (!node) 
            return NULL;
        if (new_graph.find(node) == new_graph.end()) {  //check if the node is already added in new graph
            new_graph[node] = new Node(node -> val);    //if not added then: create the copy of node
            for (auto x : node->neighbors) {    
                new_graph[node]->neighbors.push_back(cloneGraph(x));      //recursively call for all neighbors of the node and add to the new graph (dfs method)
            }
        }
        return new_graph[node];       //return the copy node which is going to be one of the nodes of the new graph
    }
