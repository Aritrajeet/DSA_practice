// https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1


void dfs(int i,int j,int x,int y,vector<vector<int>>&mat,int n,int m,int len,int &ans)
   {
       if(i>=n || j>=m || i<0 || j<0 || mat[i][j]==0)
          return;
       
       if(i==x and y==j)
       {
           ans=max(ans,len);
           return;
       }
       
       mat[i][j]=0;
  
       dfs(i+1,j,x,y,mat,n,m,len+1,ans);
       dfs(i,j-1,x,y,mat,n,m,len+1,ans);
       dfs(i-1,j,x,y,mat,n,m,len+1,ans);
       dfs(i,j+1,x,y,mat,n,m,len+1,ans);
       
       mat[i][j]=1;
          
   }
   int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd)
   {
       int ans=-1;
       int n=mat.size(),m=mat[0].size();
       
       dfs(xs,ys,xd,yd,mat,n,m,0,ans);
       return ans;
   }
