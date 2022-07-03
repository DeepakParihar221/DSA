// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int nums[])
    {
        // code here
        int total = 0;
        for(int num=0;num<n;num++) total += nums[num];
        if(total%2!=0) return 0;
        int sum = total/2;
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j] = false;
                else if(j==0) dp[i][j] = true;
                else{
                    if(nums[i-1]<=j){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    }
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum]==true?1:0;
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends