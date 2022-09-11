// https://leetcode.com/problems/subarray-sum-equals-k/

// For all numbers
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0, count=0, i=0, j=0;
        unordered_map<int, int>m;
        
        for(i=0; i<n; i++){
            sum += nums[i];
            if(sum==k)
                count++;
            if(m.find(sum-k)!=m.end())
                count+=m[sum-k]; //doesn't work with count++ {[0,0,0,0,0,0,0,0,0,0] 0}
            m[sum]++;
        } 
        
        return count;
    }
};
