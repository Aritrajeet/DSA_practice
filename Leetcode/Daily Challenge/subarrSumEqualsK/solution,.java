// Naive approach it gives time complexity of 0(n*n)

class Solution {
    public int subarraySum(int[] nums, int k) {
         int ans = 0;
        
        for(int i=0 ;i <nums.length ;i++)
        {
            int sum = 0;
            for(int j=i ; j<nums.length ;j++)
            {
                if(nums[j] + sum == k)
                    ans++;
                sum += nums[j];
            }
        }
        return ans;        
    }
}







// Optimized approach with the time complexity of o(n).

class Solution {
    public int subarraySum(int[] nums, int k) {
    
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,1);       // adding and element in hashmap as a base case. It will handle the case for the sum of k i.e. if sum = k
        int sum = 0;
        int ans = 0;
        
        for(int i=0 ;i<nums.length; i++)
        {
            sum += nums[i];
            if(hm.containsKey(sum-k))
                ans += hm.get(sum-k);        // if sum-k is there in hashmap then it means that subarray of sum k also exist in the sequence so add it. 
                                             // e.g if i= 3 sum = 20 ,and k= 5(given) . So, if subarray of sum 15 exists in hashmap then for 5 it will definately exist.
                                             // i.e (sum - (sum-k)) == k
            
            if(hm.containsKey(sum))
                hm.put(sum,hm.get(sum)+1);
            else
                hm.put(sum,1);
            
        }
        return ans;
    }
}

