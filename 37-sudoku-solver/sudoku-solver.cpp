class Solution {
public:
    bool issafe(int row,int col,vector<vector<char>>&board,int num){
        for(int j=0;j<9;j++){
            if(board[row][j]==num)
            return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==num)
            return false;
        }
        int startrow=(row/3)*3;
        int startcol=(col/3)*3;
        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==num)
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {

    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {

            if(board[row][col] == '.') {

                for(char num = '1'; num <= '9'; num++) {

                    if(issafe(row, col, board, num)) {

                        board[row][col] = num;

                        if(solve(board))
                            return true;

                        board[row][col] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};