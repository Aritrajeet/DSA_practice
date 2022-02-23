    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans ;
        int maxi = INT_MIN;
        map <int,int> freq;   //contains freq of elements.
       
        for (int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for (auto x : freq){
            if (x.second > maxi){   //since one majority element so its freq has to be maximum amongst all the elements.
                maxi = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
