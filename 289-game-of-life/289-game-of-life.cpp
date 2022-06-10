class Solution {
public:
    void solve(vector<vector<int>> &board, vector<vector<int>> dir, int n, int m){
        
        return;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        int n = board.size();
        int m = board[0].size();
        
        int size = dir.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt = 0;
                for(int k=0;k<size;k++){
                    if(i+dir[k][0]>=0 && i+dir[k][0]<n && j+dir[k][1]>=0 && j+dir[k][1]<m){
                        if(board[i+dir[k][0]][j+dir[k][1]]==1 || board[i+dir[k][0]][j+dir[k][1]]==-1){
                            cnt++;
                        }
                    }
                }
                if(board[i][j]==1&&cnt<2) board[i][j] = -1;
                else if(cnt>3 && board[i][j]==1) board[i][j] = -1;
                else if(board[i][j]==0 && cnt==3) board[i][j] = 2;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]<0) board[i][j] = 0;
                else if(board[i][j]>1) board[i][j] = 1;
            }
        }
        
        
    }
};