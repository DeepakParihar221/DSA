class Solution {
public:
    int solve(vector<int> nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr>=nums.size()) return 0;
        if(dp[curr][1+prev]!=-1) return dp[curr][prev+1];
        int l = solve(nums, curr+1, prev, dp);
        if(prev==-1 || nums[curr]>nums[prev]){
            l = max(l, 1+solve(nums, curr+1, curr, dp));
        }
        return dp[curr][prev+1] = l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<dp.size();i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};