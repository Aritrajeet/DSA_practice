class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int LIS[n];
        int ans = 1;
        for (int i=0; i<n; i++)
            LIS[i] = 1;   //Length of LIS starting from any index will be at least 1 (itself)
        for (int i=n-1; i>=0; i--){ 
            for (int j=i+1; j<n; j++){
                if (nums[j] > nums[i]){     //strictly increasing
                    LIS[i] = max(LIS[i], 1 + LIS[j]);     //we compare all LIS starting at the right of curr index and attach itself to one of those
                }
            }
            ans = max(ans,LIS[i]);      //max of LIS will have the info of where the LIS started (index) and also its length
        }
        return ans;
    }
};
