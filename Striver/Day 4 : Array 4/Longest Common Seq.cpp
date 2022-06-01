//Question: https://leetcode.com/problems/longest-consecutive-sequence/


//Solution: 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int maxi = 1;
        int count = 1;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i]+1 == nums[i+1]){
                count++;
            }
            else{
                if (nums[i] == nums[i+1])
                    continue;
                maxi = max(maxi,count);
                count = 1;
            }   
        }
        if(count > 1){
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
