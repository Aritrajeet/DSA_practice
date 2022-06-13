class Solution {
    public int[][] merge(int[][] intervals) {
        
     Arrays.sort(intervals, (a, b) -> Integer.compare(a[0],b[0]));
        
  
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
  
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(intervals[0][0]);
        temp.add(intervals[0][1]);
        
        ans.add(temp);
        
        
        for(int[] interval : intervals)
        {
            temp = new ArrayList<>();
            
            int pfirst = ans.get(ans.size()-1).get(0);
            int plast  = ans.get(ans.size()-1).get(1);
            int cfirst = interval[0];
            int clast  = interval[1];
            
            if(plast >= cfirst)
            {   
                ans.remove(ans.get(ans.size()-1));
                
                temp.add(pfirst);
                temp.add(Math.max(clast , plast));
                
                ans.add(temp);
            } 
            
            else
            {       
             temp.add(cfirst);
             temp.add(clast);
         
             ans.add(temp);   
            }
     
        }
        
        int[][] result = new int[ans.size()][2];
        

        for(int i=0 ; i<ans.size() ; i++)
        {
            for(int j=0 ; j<ans.get(0).size() ; j++)
            {
                result[i][j] = ans.get(i).get(j);
            }
        }
        
        return result;
    }
    
   
    
}
