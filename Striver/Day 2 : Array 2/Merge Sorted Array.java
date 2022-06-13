class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        
       for(int i=0 ,j=0 ; i<nums1.length ;i++)
       {
           if(nums1[i] == 0)
           {
                if(j==nums2.length)
                   break;
               
               int temp = nums2[j];
               nums2[j] = nums1[i];
               nums1[i] = temp;
               j++;
               
           }
       }
        
      Arrays.sort(nums1);  
        
    }
}
