class Solution {
    public int maxSubArray(int[] nums) {
        
        int ans = Integer.MIN_VALUE;
        int temp = 0;
        
        for(int val : nums)
        {
            if(temp > 0)
                temp += val;
            else
                temp = val;
            
            ans = Math.max(ans , temp);
        }
        
        return ans;
    }
}
