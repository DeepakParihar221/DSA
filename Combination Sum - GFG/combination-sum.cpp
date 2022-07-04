// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(vector<int> &nums, vector<int> temp, vector<vector<int>> &ans, int k, int sum, int i){
        if(i==nums.size() || sum>k) return;
        if(sum==k){
            ans.push_back(temp);
            return;
        }
        
        if(sum+nums[i]<=k){
            temp.push_back(nums[i]);
            solve(nums, temp, ans, k, sum+nums[i], i);
            // solve(nums, temp, ans, k, sum+nums[i], i+1);
            temp.pop_back();
        }
        solve(nums, temp, ans, k, sum, i+1);
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &nums, int k) {
        // Your code here
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(nums, temp, ans, k, sum, 0);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends