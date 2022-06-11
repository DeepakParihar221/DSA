class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]==1){
            return 0;
        }
        visited[i][j] = 1;
        int temp = 0;
        
        int a = solve(grid, i+1, j, visited);
        int b = solve(grid, i-1, j, visited);
        int c = solve(grid, i, j+1, visited);
        int d = solve(grid, i, j-1, visited);
        visited[i][j] = 0;
        temp = grid[i][j]+max(a, max(b, max(c, d)));
        return temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxm = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    int temp = solve(grid, i, j, visited);
                    maxm = max(maxm, temp);
                }
            }
        }
        return maxm;
    }
};