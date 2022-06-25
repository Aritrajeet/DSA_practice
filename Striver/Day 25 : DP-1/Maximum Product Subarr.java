class Solution {
    public int maxProduct(int[] nums) {
        
 
        int ans = Integer.MIN_VALUE;
        int temp_ans = 1;
        
        for(int i = 0 ; i<nums.length ;i++)
        {
            if(nums[i] == 0)
            {
                temp_ans = 1;
                ans  = Math.max(ans , 0);
                continue;
                
            }
            else
            {
                temp_ans *= nums[i];
            }
            
            ans = Math.max(ans , temp_ans);
            
        }
        
        temp_ans = 1;
        
        for(int i=nums.length-1 ; i>=0 ; i--)
        {
            if(nums[i] == 0)
            {
                temp_ans = 1;
                ans = Math.max(ans , 0 );
                continue;
            }
            
            else
            {
                temp_ans *= nums[i];
            }
            
            ans = Math.max(ans , temp_ans);
        }
        
    
        return ans;
        
    }
}
