class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        int sum = target;
        vector<int> ans;
        map<int, int> m;
        for(int i=0;i<n;i++){
            if(m.find(sum-nums[i])!=m.end()){
                ans.push_back(m[sum-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};