// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void solve(vector<vector<int>> &m, int row, int col, int n, vector<vector<int>> &visited, string dir, string temp){
        if(row<0 || col<0 || col==n || row==n || m[row][col]==0 || visited[row][col]==1)
        return;
        if(row==n-1 && col==n-1){
            ans.push_back(temp);
            return;
        }
        
        
        visited[row][col] = 1;
        solve(m, row+1, col, n, visited, dir, temp+"D");
        solve(m, row, col-1, n, visited, dir, temp+"L");
        solve(m, row, col+1, n, visited, dir, temp+"R");
        solve(m, row-1, col, n, visited, dir, temp+"U");
        visited[row][col] = 0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0) return ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string dir = "DLRU";
        string temp = "";
        solve(m, 0, 0, n, visited, dir, temp);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends