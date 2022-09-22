// https://leetcode.com/problems/flood-fill/submissions/

class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int r, int c, int color, int target){
        if(r<0 or r>=image.size() or c<0 or c>=image[0].size()){    
            return;         //boundary conditions
        }
                
        if(image[r][c] == color)        //Already colored
            return;
        if(image[r][c] == target){      //match : floodfill
            image[r][c] = color;
        }
        else return;
        //dfs traversals
        dfs(image,r-1,c,color,target);
        dfs(image,r+1,c,color,target);
        dfs(image,r,c-1,color,target);
        dfs(image,r,c+1,color,target);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};
