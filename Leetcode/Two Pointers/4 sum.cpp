// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                long long t = target - nums[i];
                t -= nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[left] + nums[right] == t){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int temp = nums[left++];
                        while(left < right and nums[left] == temp){
                            left++;
                        }
                        temp = nums[right--];
                        while(left < right and nums[right] == temp){
                            right--;
                        }
                    }
                    else if (nums[left] +nums[right] < t){
                        left++;
                    }
                    else right--;
                }
                int temp = nums[j++];
                while(j<nums.size()-2 and nums[j] == temp){
                    j++;
                }
                j--;
            }
            int temp = nums[i++];
            while(i<nums.size()-3 and nums[i] == temp){
                i++;
            }
            i--;
        }
        return ans;
    }
};
