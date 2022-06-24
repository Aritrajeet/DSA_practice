class Solution {
public:
    
    bool bin(vector<int>& nums, int target, int left, int right){
        while(left<=right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid]< target){
                left = mid+1;
            }
            else right= mid-1;
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        for (int i=1;i<nums.size();i++){
            if (nums[i] < nums[i-1])
            {
                pivot = i;
                break;
            }
        }
        vector<int>ans;
        for (int i=pivot; i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        for (int i=0; i< pivot; i++){
            ans.push_back(nums[i]);
        }
        return bin(ans,target,0,ans.size()-1);
    }
};
