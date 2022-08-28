// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;    // idx will store the unique elements in the beginning
        idx++;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                continue;
            }
            else{
                nums[idx] = nums[i+1];
                idx++;
            }
        }
        return idx;
    }
};
