// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
// 	long long int table[n+1],i;
// 	memset(table, 0, sizeof(table));
// 	table[0]=1;                 // If 0 sum is required number of ways is 1.
	vector<vector<int>> dp(4, vector<int>(n+1, 0));
	for(int i=0;i<=3;i++) dp[i][0] = 1;
	// Your code here
	int nums[3] = {3,5,10};
	for(int i=1;i<=3;i++){
	    for(int j=1;j<=n;j++){
	        if(nums[i-1]<=j){
	            dp[i][j] = dp[i-1][j] + dp[i][j-nums[i-1]];
	        }
	        else dp[i][j] = dp[i-1][j];
	    }
	}
	
	return dp[3][n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends