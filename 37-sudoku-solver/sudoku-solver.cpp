class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            
            if (board[row][i] == ch)
                return false;
            if (board[i][col] == ch)
                return false;

            int boardRow = 3 * (row / 3) + i / 3;
            int boardCol = 3 * (col / 3) + i % 3;
            if (board[boardRow][boardCol] == ch)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;

                            if (solve(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    // If no number fits here, backtrack
                    return false;
                }
            }
        }
        
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { 
        solve(board); 
    }
};