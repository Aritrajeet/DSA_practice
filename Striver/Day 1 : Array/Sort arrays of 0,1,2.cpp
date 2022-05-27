//Question: https://leetcode.com/problems/sort-colors/submissions/

//Solution: 
//Method 1 : Counting the numbers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for (int i=0; i<nums.size(); i++){
            switch(nums[i]){
                case 0: red++;
                    break;
                case 1: white++;
                    break;
                default: blue++;
                    break;
            }
        }
        for (int i=0; i<red; i++){
            nums[i] = 0;
        }
        for (int i=red; i<red + white; i++){
            nums[i] = 1;
        }
        for (int i=red + white; i<nums.size(); i++){
            nums[i] = 2;
        }
    }
};

//Method 2 : 2 ptr approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(true){
            if(nums[left] > nums[right]){
                swap(nums[left],nums[right]);
            }
            if (left == right && right != 0){
                right--;
                left = 0;
            }
            else if (left == right && right == 0){
                break;
            }
            else left++;
        }
    }
};
