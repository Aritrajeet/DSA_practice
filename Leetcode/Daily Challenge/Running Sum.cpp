//Question: https://leetcode.com/problems/running-sum-of-1d-array/

//Solution:
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int sum=0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
