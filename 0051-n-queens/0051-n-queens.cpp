class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<string> &board, int r,int c){
        int n = size(board);
        for(int i=0;i<n;i++){
            if(board[i][c]=='Q')return false;
            if(r-i>=0 && c-i>=0 && board[r-i][c-i]=='Q')return false;
            if(r-i>=0 && c+i<n && board[r-i][c+i]=='Q')return false;
        }
        return true;
    }
    
    void solve(vector<string> &board,int row){
        if(row==size(board)){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<size(board);col++){
            if(isSafe(board, row, col)){
                board[row][col]='Q';
                solve(board, row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(board, 0);
        return ans;
    }
};