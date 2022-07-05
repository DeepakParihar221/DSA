 // { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // const int MAX = 100;
 
// Returns maximum amount of gold that can be collected
// when journey started from first column and moves
// allowed are right, right-up and right-down
int maxGold(int m, int n, vector<vector<int>> gold)
{
    // Create a table for storing intermediate results
    // and initialize all cells to 0. The first row of
    // goldMineTable gives the maximum gold that the miner
    // can collect when starts that row
    int goldTable[m][n];
    memset(goldTable, 0, sizeof(goldTable));
 
    for (int col=n-1; col>=0; col--)
    {
        for (int row=0; row<m; row++)
        {
            
            int right = (col==n-1)? 0: goldTable[row][col+1];
 
            int right_up = (row==0 || col==n-1)? 0: goldTable[row-1][col+1];
 
            int right_down = (row==m-1 || col==n-1)? 0:
                             goldTable[row+1][col+1];
 
            goldTable[row][col] = gold[row][col] +
                              max(right, max(right_up, right_down));
                                                     
        }
    }

    int res = goldTable[0][0];
    for (int i=1; i<m; i++)
        res = max(res, goldTable[i][0]);
    return res;
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends