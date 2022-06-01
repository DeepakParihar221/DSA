// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int a[], int i, int j, vector<vector<int>> &dp){
        //base case
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int left, right;
            if(dp[i][k]!=-1) left = dp[i][k];
            else left = solve(a, i, k, dp);
            if(dp[k+1][j]!=-1) right = dp[k+1][j];
            else right = solve(a, k+1, j, dp);
            int temp = left+right+a[i-1]*a[k]*a[j];
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int n, int a[])
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(a, 1, n-1, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends