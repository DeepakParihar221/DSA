class Solution {
public:
    vector<vector<string>> ans;
    void solve(int col, vector<string> board, vector<int> &leftrow, vector<int> &lower, vector<int> &upper, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lower[row+col] = 1;
                upper[n-1+col-row] = 1;
                solve(col+1, board, leftrow, lower, upper, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                lower[row+col] = 0;
                upper[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++) board[i] = s;
        vector<int> row(n, 0);
        vector<int> lower(2*n-1, 0);
        vector<int> upper(2*n-1, 0);
        solve(0, board, row, lower, upper, n);
        return ans;
    }
};