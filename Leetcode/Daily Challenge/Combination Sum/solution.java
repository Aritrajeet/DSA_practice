class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        ans = new ArrayList<>();
        ArrayList<Integer> arr = new ArrayList<>();                 
        solution(candidates,target,0,arr,0);
        return ans;
        
    }
    
    static List<List<Integer>> ans;

    public static void solution(int[] candidates, int target ,int idx, ArrayList<Integer> arr, int sum)
    {  
        if(sum > target)
            return;
    
        if(sum == target)
            ans.add(new ArrayList(arr));             // adding arraylist to ans if sum == target.
        
        for(int i=idx ; i<candidates.length ; i++)
        {
           arr.add(candidates[i]);                                           // adding element to ArrayList.   
           solution(candidates,target, i , arr ,  sum + candidates[i]);      // passing idx variable i to stop it from having permutations.
           arr.remove(arr.size()-1);                                         // removing element from ArrayList i.e. backtracking.
        }
        
    }    
}
