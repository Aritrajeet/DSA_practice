    //Naive sol: O(n2) . For each index find sum of elements from itself to right of array until sum > k or end of arr. if sum = k we got a valid subarr.
    int subarraySum(vector<int>& nums, int k) {
        int ans  = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += nums[j];
                if (sum == k){
                    ans++;
                }
            }
        }
        return ans;
    }
