//Question: https://leetcode.com/problems/maximum-product-subarray/submissions/

//Solution: class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int maxi=1,mini=1;
        int ans = INT_MIN;
        for (int i=0; i<nums.size(); i++)
            ans = max(ans,nums[i]);     //get the max in the arr for initializing ans
        
        for (int i=0; i<nums.size(); i++){
            int curr_max = maxi;    //just to store the current max so that we can use it to calculate mini cuz the maxi gets changed in next step
            maxi = max (max(curr_max * nums[i] , mini * nums[i] ) , nums[i]);     // Calulate the max possible product from left to this index
            mini = min (min(curr_max * nums[i] , mini * nums[i] ), nums[i]);      //Same for min. We are keeping track of min because min product multiplied by a -ve number will result in a max product 
            ans = max(ans,maxi);  //max of all max subarr product will be our ans
        }
        return ans;
    }
};
