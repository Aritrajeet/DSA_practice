//Question: https://leetcode.com/problems/maximum-subarray/submissions/

//Solution: Kadane's algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_sum = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];     //keep adding numbers until sum is positive
            if (sum<0){
                sum = 0;      //if sum negative we dont need this element in subarray , make sum = 0
            }
            if (sum > max_sum){
                max_sum = sum;      //compare to get largest sum at any point
            }
        }
        if (max_sum == 0){       //special case when all the numbers are negative
            int maxi = INT_MIN;
            for (int i=0; i<nums.size(); i++){
                if (nums[i]>maxi)     //return the largest of all the elements
                    maxi = nums[i];
            }
            return maxi;
        }
        return max_sum;
    }
};
