class Solution {
public:
    void solve(vector<int>& nums, int i, set<vector<int>>& ans, vector<int> temp, vector<vector<int>> &res){
        if(i<0){
            if(ans.find(temp)==ans.end()){
                ans.insert(temp);
                res.push_back(temp);
            }
            return;
        }
        solve(nums, i-1, ans, temp, res);
        temp.push_back(nums[i]);
        solve(nums, i-1, ans, temp, res);
        
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size()-1;
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(nums, n, ans, temp, res);
        return res;
    }
};