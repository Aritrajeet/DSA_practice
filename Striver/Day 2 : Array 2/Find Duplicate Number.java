class Solution {
    public int findDuplicate(int[] nums) {
        
        int max = Integer.MIN_VALUE;
        int sum = 0;
        
        for(int i=0 ; i<nums.length ;i++)
        {
         
          max = Math.max(max , nums[i]);       
          sum += nums[i];   
        }
        
        int count = nums.length;
        
        int rsum = max*(max+1)/2;
        int extra = nums.length-max;
        
        return (sum-rsum)/extra;

    }
}
