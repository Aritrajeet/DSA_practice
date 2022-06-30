class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int key[n];
        bool mst[n];
        //initialization
        for (int i=0; i<n; i++){
            key[i] = INT_MAX;
            mst[i] = false;
        }
        key[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;     //min heap
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second; //minimum wt node
            pq.pop();
            mst[node] = true;
            for (auto x : adj[node]){
                int next_node = x[0];
                int wt = x[1];
                if (!mst[next_node] and wt < key[next_node]){
                    key[next_node] = wt;
                    pq.push({wt,next_node});
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans += key[i];
        }
        return ans;
    }
};
