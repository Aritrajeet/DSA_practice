    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        int low = 0; // starting index value
        int high = n - 1; // ending index value
        while (low <= high) // if Low > high exit the loop 
        {
            int mid = low + (high - low) / 2; //  mid idx value
            if (nums[mid] == target) // search successful
                return mid;
            else if (nums[mid] < target) // number maybe in right part
                low = mid + 1;
            else //     number may be in left part
                high = mid - 1;
        }
        return -1;
    }
