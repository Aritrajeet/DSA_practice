class Solution {
public:
    
    bool isCycle(vector<int> adj[],vector<bool> &visited,vector<bool> &dfsvisited,int sv){
        visited[sv]=1;
        dfsvisited[sv]=1;
        for(auto it:adj[sv]){
              if(!visited[it]){
                  if(isCycle(adj,visited,dfsvisited,it))
                      return true;
              }
        else if(dfsvisited[it])
            return true;
        }
        dfsvisited[sv]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> adj[numCourses];
        for(int i=0;i<n;i++){
         adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses,0);
        vector<bool> dfsvisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(isCycle(adj,visited,dfsvisited,i))
                    return false;
            }
        }
     return true;   
    }
};
