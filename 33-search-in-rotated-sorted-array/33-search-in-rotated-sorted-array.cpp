class Solution {
public:
    int helper(vector<int> nums, int l, int r, int target){
        int mid = (l+r)/2;
        if(l>r)
            return -1;
        if(nums[mid]==target)
            return mid;
        
        if(nums[l]<=nums[mid]){
            if(target>=nums[l] && target<=nums[mid]){
                return helper(nums, l, mid-1, target);
            }
            else
                return helper(nums, mid+1, r, target);
        }
        else{
            if(target>=nums[mid] && target<=nums[r])
                return helper(nums, mid+1, r, target);
            else
                return helper(nums, l, mid-1, target);
            
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
            
        int ans = helper(nums, 0, n-1, target);
        
        return ans;
    }
};