//    Better approach is to use prefix sum. We store the sum as index in a map and count the occurence of the sum (i.e. the no. of subarrays with that sum in prefix)
int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map <int,int> m;
        for (int i=0; i<n; i++){
            sum += nums[i];
            if (sum == k){  //valid subarr starting from first index
                count++;
            }
            if (m.find(sum-k) != m.end()){ //Here we consider that subarray ending at ith pos has sum = k . That means it is a valid substring.
                count += m[sum-k];         //So, the sum of elements before this subarray should be sum-k. The map has the count of such subarrays
            }
            m[sum]++;     //using map , we count the no of subarrays to the left with this sum.
        }
        return count;
    }
