class Solution {
    public int minStartValue(int[] nums) {
        
     
        int min = Integer.MAX_VALUE;   // initialize min value with infinity.
        int sum = 0;
        
        for(int i=0 ;i<nums.length ;i++)
        {
           sum += nums[i];
           min = Math.min(min,sum);                // finding the min possible sum during the entire iteration of an array.
        }
        
        return min<0 ? Math.abs(min)+1 : 1;     // if min is -ve then return |min| +1 for being > 0  else return 1 because in question it is given that it should start with 1.
    }
}
