	void topoSortDFS(int node, int n, vector<int> adj[], vector<bool> &vis, stack<int> &st){
	    vis[node] = true;
	    for (auto x : adj[node]){
	        if (!vis[x]){
	            topoSortDFS(x,n,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<bool> vis(n,false);
	    stack<int>st;
	    for (int i=0; i<n; i++){
	        if (!vis[i]){
	            topoSortDFS(i,n,adj,vis,st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
