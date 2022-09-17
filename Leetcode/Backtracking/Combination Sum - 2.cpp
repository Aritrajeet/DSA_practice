// https://leetcode.com/problems/combination-sum-ii/


class Solution {
public:
    vector<vector<int>> ans;
    
    void printCombo(int idx,  int target, vector<int>& candidates, vector<int> &combo){
        //base cases
        if(target == 0){
            ans.push_back(combo);
            return;
        }
        for (int i = idx; i<candidates.size(); i++){      // loop for all elements. Since we have sorted so no need to combine with prev elements
            if(candidates[i] > target)      // No need to make further calls
                break;
            if(i != idx and candidates[i] == candidates[i-1])     // If same recursion call(for same no) no need to repeat
                continue;
            combo.push_back(candidates[i]);     // consider curr ele in the combination
            printCombo(i+1,target-candidates[i],candidates, combo);     // computation
            combo.pop_back();     // backtrack
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>combo;
        printCombo(0,target,candidates,combo);
        return ans;
    }
};
