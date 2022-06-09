class Solution {
    public void nextPermutation(int[] nums) {
        
        int j = nums.length-2;
        
        while(j>=0)
        {
            if(nums[j] < nums[j+1])
                break;
            else
                j--;
        }
        

        
        int temp = j;


        
        for(int i=nums.length-1 ; i>temp && temp>=0 ; i--)
        {
            
            if(nums[i] > nums[temp])
            {

                int temp1 = nums[temp];
                nums[temp] = nums[i];
                nums[i] = temp1;
                
                break;
            }
            
        }
        

        int i = temp+1;
        j = nums.length-1;
        
        while(i<j)
        {
            int temp1 = nums[i];
            nums[i] = nums[j];
            nums[j]= temp1;
            
            i++;
            j--;
        }
        
    }
    
        
}



