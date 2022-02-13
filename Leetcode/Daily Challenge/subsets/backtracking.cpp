    //Order for [1,2,3] = {[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]}
    void sub(vector<int>& nums,vector<int> &temp, int pos, vector<vector<int>> &ans){
            ans.push_back(temp);
            for (int i=pos;i<nums.size(); i++){   //check subsets starting from each indx
                temp.push_back(nums[i]);
                sub(nums,temp,i+1,ans);       //consider that present element is included in the subset.
                temp.pop_back();      //backtrack here. Here we assume present element is excluded in the subset.
            }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {  //main
        vector<vector<int>>ans;
        vector<int> temp;
        sub(nums,temp,0,ans);
        return ans;
    }
