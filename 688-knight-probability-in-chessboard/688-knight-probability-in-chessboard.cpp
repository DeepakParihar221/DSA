class Solution {
public:
    double dp[26][26][101];
    double solve(int i, int j, int n, int k, vector<vector<vector<double>>> &dp){
        if(i<0 || i>=n || j<0 || j>=n){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[i][j][k]!=0) return dp[i][j][k];
        double val = 0;
        val += solve(i+2, j-1, n, k-1, dp) + solve(i+2, j+1, n, k-1, dp) + solve(i-2, j-1, n, k-1, dp) + solve(i-2, j+1, n, k-1, dp) + solve(i+1, j+2, n, k-1, dp) + solve(i-1, j+2, n, k-1, dp) + solve(i+1, j-2, n, k-1, dp) + solve(i-1, j-2, n, k-1, dp);
        
        val /= 8;
        return dp[i][j][k] = val;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1)));
        double valid = solve(row, column, n, k, dp);
        return valid;
    }
};