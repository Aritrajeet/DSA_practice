//question: https://leetcode.com/problems/partition-equal-subset-sum/

//solution:
class Solution {
public:
    
    bool subsetSum(vector<int>nums,int target){
        bool t[nums.size()+1][target+1];
        for (int j=0; j<target+1; j++)
            t[0][j] = 0;
        for (int i=0; i<nums.size()+1; i++)
            t[i][0] = 1;
        for (int i=1; i<nums.size()+1; i++){
            for (int j=1; j<target+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[nums.size()][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (auto x: nums){
            sum += x;
        }
        if (sum % 2 != 0)
            return false;
        return subsetSum(nums,sum/2);
    }
};
