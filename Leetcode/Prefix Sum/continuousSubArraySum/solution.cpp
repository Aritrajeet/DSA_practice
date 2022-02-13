    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;    //prefix sum
        int last_mod = 0;
        unordered_set<int> s;   //s stores the remainder of prefix sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];         
            int mod = sum % k;
            if (s.count(mod))   // If the remainder is same again means we have a subarr that has sum divisible by multiple of k.
                return true;
            s.insert(last_mod); //the reason of inserting curr mod in next iteration is that the minimum size must be at least 2.
            last_mod = mod;
        }
        return false;
    }
};
