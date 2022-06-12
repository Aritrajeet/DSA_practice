
class Solution {
    public int maxProfit(int[] prices) {
        
        
        int min = prices[0];
        int profit = 0;
        int ans = 0;
        
        for(int val : prices)
        {
            min = Math.min(min , val);
            
            profit = val - min;
            
            if(profit > 0)
                ans = Math.max(ans , profit);
                
        }
        
        return ans;
        
    }
}
