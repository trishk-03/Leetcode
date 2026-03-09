class Solution {
private:
    bool dfs(vector<vector<char>> &board, int idx, int i, int j , string &word){
        if(idx == word.length()) return true;

        if(i<0 || j<0 || i>= board.size() || j>= board[0].size() || board[i][j] !=  word[idx])
        return false;
        

        char temp = board[i][j];
        board[i][j] ='*';

        bool found = dfs(board, idx+1, i + 1, j, word) ||
                     dfs(board, idx +1, i - 1, j, word) ||
                     dfs(board, idx+1, i, j + 1, word) ||
                     dfs(board, idx +1, i, j - 1, word);

        board[i][j]= temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
     int row = board.size();
     int col = board[0].size();

     for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            if(board[i][j]== word[0]){
            if(dfs(board, 0,i,j,word))
            return true;
            }
        }
    }
    return false;   
    }
};