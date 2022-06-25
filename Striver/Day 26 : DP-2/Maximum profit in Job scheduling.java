
class Solution
{
    int[] JobScheduling(Job arr[], int n)
    {
        int job = 0;
      
        Arrays.sort( arr, (j1, j2) -> j2.profit - j1.profit );
       
        for(Job val : arr)
         job = Math.max(job , val.deadline);
        
        int[] ans = new int[2];
        
        boolean[] temp = new boolean[job+1];
        
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=arr[i].deadline ; j>0 ; j--)
            {
                if(temp[j] == false)
                {
                    ans[0] = ans[0]+1;
                    ans[1] = ans[1] + arr[i].profit;
                    temp[j] = true;
                    break;
                }
            }
        }
        
        return ans;
        
    }
}
