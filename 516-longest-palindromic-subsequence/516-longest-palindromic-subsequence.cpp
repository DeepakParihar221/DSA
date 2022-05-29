class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.length();
        int dp[n+1][n+1];

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(s[i-1]==s1[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // int i=n, j=n;
        // string ans = "";
        // while(i>=0 && j>=0){
        //     if(s[i-1]==s1[j-1]){
        //         ans += s[i-1];
        //     }
        //     else{
        //         if(dp[i-1][j]>dp[i][j-1]){
        //             ans += s[i-1];
        //             i--;
        //         }
        //         else{
        //             ans += s[j-1];
        //             j--;
        //         }
        //     }
        // }
        // reverse(ans.begin(), ans.end());
        return dp[n][n];
    }
};