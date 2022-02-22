  //Order of answer for [1,2,3] : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]]
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteRec(nums, 0, ans);
        return ans;
    }
    
    void permuteRec(vector<int> &nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {     // goal reached: we have a solution
            ans.push_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permuteRec(nums, i + 1, ans);   
            swap(nums[i], nums[j]);         //backtrack
        }
    }
