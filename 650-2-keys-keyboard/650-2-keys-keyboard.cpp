class Solution {
public:
    int minm = INT_MAX;
    int dp[1001][1001];
    void solve(int i, int n, int steps, int prev){
        if(i==n){
            minm = min(minm, steps);
            return;
        }
        if(i>n || prev>n) return;
        
        if(2*i<n)
        solve(i+i, n, steps+2, i);
        solve(i+prev, n, steps+1, prev);
        return;
    }
    int minSteps(int n) {
        if(n==1) return n-1;
        if(n==2) return n;
        
        solve(2, n, 0, 1);
        return minm+2;
    }
};