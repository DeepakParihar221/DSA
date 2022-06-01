class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=amount;i++) dp[0][i] = INT_MAX-1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(i==1){
                    if(j%coins[0]==0)
                        dp[i][j] = j/coins[0];
                    else
                        dp[i][j] = INT_MAX-1;
                    continue;
                }
                
                if(j>=coins[i-1]){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
                
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        if(dp[n][amount]==INT_MAX-1) return -1;
        return dp[n][amount];
    }
};