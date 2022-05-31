class Solution {
public:
    int solve(vector<string>& strs, int m, int n, int index,vector<vector<vector<int>>> &dp){
        if(index==strs.size()) return 0;
        if(dp[m][n][index]!=-1) return dp[m][n][index];
        
        int c0 = count(strs[index].begin(), strs[index].end(), '0');
        int c1 = strs[index].size()-c0;
        
        if(m-c0>=0 && n-c1>=0){
            dp[m][n][index] = max(1+solve(strs, m-c0, n-c1, index+1, dp), solve(strs, m, n, index+1, dp));
        }
        else
            dp[m][n][index] = solve(strs, m, n, index+1, dp);
        return dp[m][n][index];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(l+1, -1)));
        int ans = solve(strs, m, n, 0, dp);
        return ans;
    }
};