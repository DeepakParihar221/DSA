// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& nums){
      //Code here
      int min_now = nums[0];
      int minm = nums[0];
      int n = nums.size();
      for(int i=1;i<n;i++){
          
          if(min_now>0) min_now = nums[i];
          else min_now += nums[i];
          
          minm = min(minm, min_now);
      }
      return minm;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends