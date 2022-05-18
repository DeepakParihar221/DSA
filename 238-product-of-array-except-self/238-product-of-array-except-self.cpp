class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, pre(n,nums[0]), suf(n, nums[n-1]);
        for(int i=1;i<n;i++){
            pre[i] = nums[i]*pre[i-1];
        }
        for(int i=n-2;i>0;i--){
            suf[i] = nums[i]*suf[i+1];
        }
        ans.push_back(suf[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(pre[i-1]*suf[i+1]);
        }
        ans.push_back(pre[n-2]);
        return ans;
    }
};