class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i,int j,int index){
        if(index==word.length())return true;
        int m = board.size(), n = board[0].size();
        if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[index]||board[i][j]=='!'){
            return false;
        }
        char c = board[i][j];
        board[i][j] = '!';
        bool up = solve(board, word, i-1, j, index+1);
        bool left = solve(board, word, i, j-1, index+1);
        bool right = solve(board, word, i, j+1, index+1);
        bool down = solve(board, word, i+1, j, index+1);
        board[i][j]=c;
        return up||left||right||down;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[index]){
                    if(solve(board, word, i, j, index)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};