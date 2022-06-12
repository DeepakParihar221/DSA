class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //first find LCS
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = s1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int lcsascii = dp[n][m];
        int del1 = 0, del2 = 0;
        for(int i=0;i<n;i++){
            del1 += s1[i];
        }
        for(int i=0;i<m;i++){
            del2 += s2[i];
        }
        int deleted = (del1-lcsascii)+(del2-lcsascii);
        return deleted;
    }
};