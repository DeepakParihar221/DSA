class Solution {
public:
    
    void solve(vector<int> &nums, vector<int> &temp, int k, int index, vector<vector<int>> &ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(index>=nums.size()){
            return;
        }
        
        solve(nums, temp, k, index+1, ans);
        temp.push_back(nums[index]);
        solve(nums, temp, k, index+1, ans);
        temp.pop_back();
        
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<int> nums(n);
        for(int i=1;i<=n;i++){
            nums[i-1] = i;
        }
        vector<vector<int>> ans;
        solve(nums, temp, k, 0, ans);
        
        return ans;
    }
};