class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        
        ans = new ArrayList<>();
        ArrayList<Integer> arr = new ArrayList<>();
        solution(nums,0,arr);
        return ans;
        
    }
    
    static List<List<Integer>> ans;
    
    public static void solution(int[] nums , int idx , ArrayList<Integer> arr)
    {
        if(idx == nums.length)
        {
            ans.add(new ArrayList(arr));
            return;
        }
        
        arr.add(nums[idx]);
        solution(nums, idx+1 , arr);                  //  recursion element with containing idx element.
        arr.remove(arr.size()-1);                     // backtracking step to remove the last element from arraylist.
        
        solution(nums, idx+1 , arr);                 // recursion without containing idx element.
        
    }
    
}
