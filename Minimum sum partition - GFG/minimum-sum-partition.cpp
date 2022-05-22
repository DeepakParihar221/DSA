// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    sum += a[i];
	    
	    bool v[n+1][sum+1];
	    for(int i=0;i<=sum;i++)
	    v[0][i] = false;
	    for(int i=0;i<=n;i++)
	    v[i][0] = true;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(a[i-1]<=j)
	            v[i][j] = v[i-1][j-a[i-1]] || v[i-1][j];
	            else
	            v[i][j] = v[i-1][j];
	        }
	    }
	    int index = 0;
	    for(int i=sum/2;i>=0;i--){
	        if(v[n][i]==true){
	            index = i;
	            break;
	        }
	    }
	    return (sum-2*index);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends