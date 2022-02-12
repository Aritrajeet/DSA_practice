    //idea is to comnpare left sum and right sum at every index
int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return 0;
        
        int total = 0;
        for (int i =0; i<n; i++){
            total += nums[i];     //get sum of all numbers
        }
        int left_sum = 0;
        int right_sum = total - nums[0];
        
        for (int i=0; i<n; i++){
            if (left_sum == right_sum){     
                return i;
            }
            if(i == n-1) return -1;     //No pivot exisits
            left_sum += nums[i];        //shifting left ptr
            right_sum -= nums[i+1];     //shifting right ptr
        }
        return -1;
    }
