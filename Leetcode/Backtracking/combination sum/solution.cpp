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

// Another approach - Take and not take
class Solution {
public:
    void combinationRec(vector<int>&nums, int target, vector<int> &temp, vector<vector<int>> &ans, int idx){
        if(idx >= nums.size())
            return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0){
            return;
        }
        // take curr ele
        temp.push_back(nums[idx]);
        combinationRec(nums, target-nums[idx] ,temp, ans, idx);
        temp.pop_back();
        
        // dont take curr ele
        combinationRec(nums,target,temp,ans,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationRec(candidates, target, temp, ans, 0);
        return ans;
    }
};
