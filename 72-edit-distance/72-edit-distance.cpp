class Solution {
public:
    int solve(string word1, string word2, int n, int m, vector<vector<int>> &dp){
        //base condition
        if(n<0){
            return m+1;
        }
        else if(m<0){
            return n+1;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(word1[n]==word2[m]){
            return solve(word1, word2, n-1, m-1, dp);
        }
        
        int insert = solve(word1, word2, n, m-1, dp);
        int delet = solve(word1, word2, n-1, m, dp);
        int replace = solve(word1, word2, n-1, m-1, dp);
        
        dp[n][m] = 1+min(insert, min(delet, replace));
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, n-1, m-1, dp);
    }
};