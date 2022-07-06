// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}
    int solve(string s, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(isPalindrome(s, i, j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int l, r;
            if(dp[i][k]!=-1) l = dp[i][k];
            else l = solve(s, i, k, dp);
            
            if(dp[k+1][j]!=-1) r = dp[k+1][j];
            else r = solve(s, k+1, j, dp);
            
            int temp = 1+l+r;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(str, 0, n-1, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends