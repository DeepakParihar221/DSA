class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &triangle, int row, int col){
        if(row>=triangle.size() || col>=triangle[row].size()){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        
        int p = solve(triangle, row+1, col);
        int q = solve(triangle, row+1, col+1);
        dp[row][col] = triangle[row][col]+min(p, q);
        return dp[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(triangle, 0, 0);
        return ans;
    }
};