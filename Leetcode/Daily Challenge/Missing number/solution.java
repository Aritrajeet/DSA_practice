class Solution {
    public int missingNumber(int[] nums) {
    
        Arrays.sort(nums);
        int idx = 0;
        
        for(int i=0 ; i<=nums.length ;i++) {
            
            if(i==nums.length)
                idx = i;
            
            else if(nums[i] == i)
                continue;
            
            else
            {
                idx = i;
                break;
            }
            
        }
        
        return idx;
        
    }
}
