    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        vector<int> dist(n,INT_MAX);
        priority_queue < pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>> > pq;  //min heap of pair containing <dist,next_node>
        dist[src] = 0;
        pq.push({0,src});     //src has 0 dist
        while(!pq.empty()){
            int distance = pq.top().first;      //top will have min distance path
            int node = pq.top().second;
            pq.pop();
            for (auto x : adj[node]){
                int next_node = x[0];
                int dist_node = x[1];
                if(distance + dist_node < dist[next_node]){
                    dist[next_node] = dist[node] + dist_node;
                    pq.push({dist[next_node],next_node});     //whenever we get a shortest path add to the queue
                }
            }
        }
        return dist;
    }
