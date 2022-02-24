/* We try to guess value for a particular grid by checking the sudoku conditions(). If it is safe we keep it there and move on to next grids. 
If while moving forward we find that for a particular cell we are not able to put any values from 1 to 9 it means that the current assumption was wrong and we BACKTRACK here.
We make the cell empty again and check for other values.
*/

bool isSafe(vector<vector<char>> &board, int i, int j, char n){
        //check current row
        for (int c=0; c<9; c++){
            if ( board[i][c] == n )
                return false;
        }
        
        //check current col
        for (int r=0; r<9; r++){
            if ( board[r][j] == n )
                return false;
        }
        
        //check 3X3 grids
        int i1 = i - i%3;   //start row index of the grid
        int j1 = j - j%3;   //start col index of the grid
        for (int r= i1; r<i1+3 ; r++){
            for (int c=j1; c<j1+3; c++){
                if (board[r][c] == n)
                    return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int i, int j){
        if (i == 9) return true;      // last row is completed. Thus the sudoku is solved !
        if (j == 9) return solve(board,i+1,0);        //end of current row -> move to next row
        if (board[i][j] != '.')
                return solve(board,i,j+1);        //current cell is already solved -> move to next        //empty cell
        for(char n='1'; n<='9'; n++){            //try all numbers
             if (isSafe(board,i,j,n)){         //check if current value is safe at this position
                    board[i][j] = n;      
                    if (solve(board,i,j+1))   //if we are able to solve remaining grid, means this position is correct
                        return true;
        
                    board[i][j] = '.';    //[BACKTRACK] we are not able to solve remaining grid.So, our assumption is wrong -> change it to empty cell and try for other values.
             }
        }
        
        return false;           // we cant solve the sudoku -> sudoku not solvable
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
