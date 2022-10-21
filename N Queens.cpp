void addSolution (vector <vector <int> > &board, vector <vector <int> > &ans, int n)
{
    vector <int> temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe (int row, int col, vector <vector <int> > &board, int n){
    
    int x = row; 
    int y = col;
    
    while(y >= 0){
        if(board[x][y] == 1)
            return false;
        
        y--;
    }
    x = row;
    y = col;
    
    // check for diagonal
    while (x >= 0 && y >= 0){
        if (board[x][y] == 1)
            return false;
        
        y--;
        x--;
    }
    
    // Check for diagonal
    x = row;
    y = col;
    
    while (x < n && y >= 0){
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
    
}

void solve (int col,  vector <vector <int> > &ans, vector <vector <int> > &board, int n )
{
   if (col == n){
       addSolution(board,  ans, n);
       return;
   }
    
    // Solve one case using recursion
    
    for (int row = 0; row < n; row++){
        if (isSafe (row, col, board, n)){
            // if placing is safe
            board[row][col] = 1;
            solve(col + 1, ans, board, n );
            //backtrack
            board[row][col] = 0;
            
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    
    vector <vector <int> > board (n, vector <int> (n, 0));
    
    vector <vector <int> > ans;
    
    solve (0, ans, board, n);
    
    return ans;
    
}

// TIme Complexity - O(N!)
// Space Complexity - O(N * N)





// LeetCode Challlenge ..........................................................................................................................

class Solution {
public:
    
    void solve(int  col, vector<string> &board, vector<vector<string>> &ans, 
              vector<int> &leftRow, vector<int> &upperDiagonal, 
              vector <int> &lowerDiagonal, int n)
        
    {
        
        if (col == n){
            ans.push_back(board);
            return;
        }
        
        
      for (int row =  0; row < n; row++){
         if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n - 1 + col - row] == 0){
               
        
        board[row][col] = 'Q';
        leftRow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        
        solve (col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        board[row][col]  = '.';
        leftRow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal [n - 1 + col - row] = 0;
                
                
                
            }
        }
        
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector <string> board(n);
        string s(n, '.');
        
        for (int i = 0; i< n; i++)
            board[i] = s;
        
        
        vector <int> leftRow(n, 0), upperDiagonal (2 * n - 1, 0), lowerDiagonal (2 * n - 1, 0);
        
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        
        return ans;
        
    }
};
