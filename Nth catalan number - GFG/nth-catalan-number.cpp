// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    // cpp_int solve(cpp_int n, vector<cpp_int> &dp){
    //     if(n<=1) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     cpp_int res = 0;
    //     for(cpp_int i=0;i<n;i++){
    //         res += solve(i, dp)*solve(n-1-i, dp);
    //     }
    //     return dp[n] = res;
    // }
    
    cpp_int findCatalan(int n) 
    {
        //code here
        
        cpp_int catalan[n + 1];
 
    // Initialize first two values in table
        catalan[0] = catalan[1] = 1;
     
        // Fill entries in catalan[] using recursive formula
        for (int i = 2; i <= n; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++)
                catalan[i] += catalan[j] * catalan[i - j - 1];
        }
     
        // Return last entry
        return catalan[n];
        
        // vector<cpp_int> dp(n+1, -1);
        // dp[0] = 1;
        // dp[1] = 1;
        // cpp_int res = solve((cpp_int)n, dp);
        // return res;
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends