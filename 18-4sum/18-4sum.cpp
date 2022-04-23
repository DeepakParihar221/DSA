class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int start = j+1, end = n-1;
                int newtarget = target-nums[i]-nums[j];
                while(start<end){
                    int twosum = nums[start]+nums[end];
                    if(twosum<newtarget) start++;
                    else if(twosum>newtarget) end--;
                    else {
                        vector<int> mid ;
                        mid.push_back(nums[i]);
                        mid.push_back(nums[j]);
                        mid.push_back(nums[start]);
                        mid.push_back(nums[end]);
                        res.push_back(mid);
                        
                        while(start<end && mid[2]==nums[start]) start++;
                        while(start<end && mid[3]==nums[end]) end--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }
        return res;
    }
};