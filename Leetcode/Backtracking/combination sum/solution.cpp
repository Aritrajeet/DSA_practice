    // NOTE: Java solution at: Leetcode/daily challenge/combination sum
    void combinationSumRec(vector<int> candidates, int target, int sum , int idx, vector<vector<int>> &ans , vector<int> temp){
        if (sum == target){
            ans.push_back(temp);
            return;
        }
        if (sum > target){
            return;
        }
        for (int i=idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);  //consider that present element is part of subset
            combinationSumRec(candidates,target,sum + candidates[i],i,ans,temp);
            temp.pop_back();        //consider that present element is not part of the subset (backtrack)
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSumRec(candidates, target, 0 , 0, ans,temp);         // sum=0 and index=0
        return ans;
    }
