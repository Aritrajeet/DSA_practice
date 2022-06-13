class Solution {
    public void rotate(int[][] matrix) {
        
        int len = matrix.length;
        
        int n = 0;
        
     
        while(n < matrix.length/2)
        {
        
        for(int i=0 ; i<matrix.length-2*n-1 ; i++)
        {
    
            /*
            int temp1 = matrix[n][n+i];
            int temp2 = matrix[n+i][matrix[0].length-1-n];
            int temp3 = matrix[matrix.length-1-n][matrix[0].length-i-1-n];
            int temp4 = matrix[matrix.length-i-1-n][n];
            */
  
            
            int r1 = n;
            int c1 = n+i;
            
            int r2 = n+i;
            int c2 = matrix[0].length-1-n;
            
            int r3 = matrix.length-1-n;
            int c3 = matrix[0].length-i-1-n;
            
            int r4 = matrix.length-i-1-n;
            int c4 = n;
            
            int temp = matrix[r1][c1];
            
            matrix[r1][c1] = matrix[r4][c4];
            matrix[r4][c4] = matrix[r3][c3];
            matrix[r3][c3] = matrix[r2][c2];
            matrix[r2][c2] = temp;
                                    
              
        }
        
        n++;
    }
          
    }
}
