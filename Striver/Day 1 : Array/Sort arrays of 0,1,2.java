class Solution {
    public void sortColors(int[] nums) {
     
        int i=0;
        int j=nums.length-1;
        int k=0;
        
        
        while(k<=j)
        {
            if(nums[k] == 2)
            {
                
                int temp = nums[j];
                nums[j] = nums[k];
                nums[k] = temp;
                
                
                j--;
                
            }
            
            else if(nums[k] == 0)
            {
                
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                
                i++;
                k++;
            }
                
            
            else
                k++;
            
            
        }
       
        
    }
}
