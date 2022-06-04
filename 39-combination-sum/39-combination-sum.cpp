class Solution {
public:
    
    void solve(vector<int>& candidates, int target, int i, vector<int> temp, vector<vector<int>> &ans){
        if(i>=candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i, temp, ans);
            temp.pop_back();
        }
        solve(candidates, target, i+1, temp, ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, target, 0, temp, ans);
        
        return ans;
    }
};