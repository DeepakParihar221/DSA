class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> v, int n, int i){
        if(i==n){
            ans.push_back(v);
            return;
        }
        helper(nums, ans, v, n, i+1);
        v.push_back(nums[i]);
        helper(nums, ans, v, n, i+1);
        
        
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> v;
        helper(nums, ans, v, n, 0);
        
        return ans;
    }
};