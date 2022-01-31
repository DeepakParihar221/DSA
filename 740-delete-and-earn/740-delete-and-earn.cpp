class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> value(10001, 0);
        int n = nums.size();
        for(int i=0;i<n;++i){
            value[nums[i]] += nums[i];
        }
        
        vector<int> dp(10001, 0);
        dp[0] = value[0];
        dp[1] = value[1];
        for(int i=2;i<value.size();++i){
            dp[i] = max(value[i]+dp[i-2], dp[i-1]);
        }
        return dp[10000];
    }
};