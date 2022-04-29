// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        map<int, int> m;
        int maxm = 0, sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum==0){
                maxm = i+1;
            }
            else{
                if(m.find(sum)!=m.end()){
                    maxm = max(maxm, i-m[sum]);
                }
                else{
                    m[sum] = i;
                }
            }
        }
        return maxm;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends