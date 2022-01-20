class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minm = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;++i){
            sum += nums[i];
            minm = min(minm, sum);
        }
        
        return -minm+1;
    }
};