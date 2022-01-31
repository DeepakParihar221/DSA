class Solution {
public:
    // int dp[401][401] = {0};
    int helper(vector<int> nums, vector<int> &dp, int i){
        if(i==0)
            return nums[0];
        if(i==1)
            return max(nums[0], nums[1]);
        
        if(dp[i]!=-1)
            return dp[i];
        
        dp[i] = max(helper(nums, dp, i-1),helper(nums, dp ,i-2)+nums[i]);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0], nums[1]);
        vector<int> dp(n, -1);
        int temp = helper(nums, dp, n-1);
        return dp[n-1];
    }
};