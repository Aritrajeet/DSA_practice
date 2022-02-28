    vector<string>ans;
    
    vector<string> summaryRanges(vector<int>& nums) {
      
      //corner cases
        if (nums.size() == 0) return ans;
        if (nums.size() == 1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int start = 0;
        for (int i=1; i<=nums.size(); i++){
            if(i==nums.size()){
                if(start == i-1){
                    ans.push_back(to_string(nums[i-1]));      //single char when start did not change
                }
                break;
            }
            string range="";
            while(i < nums.size() && nums[i]-1 == nums[i-1]){     //find the end of curr pair
                i++;
            }
            if(start == i-1){
                ans.push_back(to_string(nums[start]));        //same logic
                start++;
                continue;
            }
            range = to_string(nums[start]) + "->" + to_string(nums[i-1]);     //add curr pair to ans
            ans.push_back(range);
            start = i;      //start with next pair
        }
        return ans;
    }
