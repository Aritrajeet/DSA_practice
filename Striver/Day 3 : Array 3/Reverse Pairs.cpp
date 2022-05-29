//Question: https://leetcode.com/problems/reverse-pairs/

//Solution : Method 1 : Brute force  O(n2)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        for (int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] > 2*nums[j])
                    count++;
            }
        }
        return count;
    }
};
//Method 2 : Merge sort
