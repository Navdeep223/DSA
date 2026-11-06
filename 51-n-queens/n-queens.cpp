class Solution {
public:
    bool issafe(int row,int col,int n,vector<string>&board){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
            return false;
        }
        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
            return false;
            i--;
            j--;
        }
        int t=row-1;
        int s=col+1;
        while(t>=0 && s<n){
            if(board[t][s]=='Q')
            return false;
            t--;
            s++;
        }
        return true;
    }
    void solve(vector<string>&board,int row,int n,vector<vector<string>>&ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(row,col,n,board)){
                board[row][col]='Q';
                solve(board,row+1,n,ans);
                board[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(board,0,n,ans);
        return ans;
    }
};