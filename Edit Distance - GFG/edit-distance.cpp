// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int solve(string s, string t, int n, int m, vector<vector<int>> &dp){
        if(n<0) return m+1;
        if(m<0) return n+1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m] = solve(s, t, n-1, m-1, dp);
        }
        
        int del = solve(s, t, n-1, m, dp);
        int insert = solve(s, t, n, m-1, dp);
        int replace = solve(s, t, n-1, m-1, dp);
        
        return dp[n][m] = 1+min(del, min(insert, replace));
        
    }
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t, n-1, m-1, dp);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends