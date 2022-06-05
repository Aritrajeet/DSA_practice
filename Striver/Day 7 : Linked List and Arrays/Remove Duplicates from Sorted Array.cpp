//Question : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//Solution:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        idx++;      //since first element will always stay in its position
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                continue;
            }
            else{
                nums[idx] = nums[i+1];      //if unique element found keep it to its desired place
                idx++;
            }
        }
        return idx;
    }
};
