// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col, int n , vector<int> temp, vector<vector<int>> &ans, vector<int> rows, vector<int> &upper, vector<int> &lower){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(rows[row]!=1 && lower[row+col]!=1 && upper[n+col-row-1]!=1){
                rows[row] = 1;
                upper[n+col-row-1] = 1;
                lower[row+col] = 1;
                temp.push_back(row+1);
                solve(col+1, n, temp, ans, rows, upper, lower);
                temp.pop_back();
                rows[row] = 0;
                upper[n+col-row-1] = 0;
                lower[row+col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> temp;
        vector<int> rows(n, 0), upper(2*n-1, 0), lower(2*n-1, 0);
        vector<vector<int>> ans;
        solve(0, n, temp, ans, rows, upper, lower);
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends