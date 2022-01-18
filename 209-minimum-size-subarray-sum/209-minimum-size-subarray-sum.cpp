class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int sum = 0;
        int minm = INT_MAX;
        while(j<n){
            sum += nums[j];
            
            while(sum>=target){
                minm = min(minm, j-i+1);
                sum -= nums[i++];
            }
            
            j++;
        }
        if(minm==INT_MAX)
            return 0;
        
        return minm;
    }
};