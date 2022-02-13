class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int sum = 0, maxm = INT_MIN;
        while(j<n){
            sum += nums[j];
            maxm = max(maxm, sum);
            
            if(sum<0){
                i = j+1;
                sum = 0;
            }
            j++;
        }
        if(maxm==INT_MIN)
            return sum;
        return maxm;
    }
};