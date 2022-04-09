class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int i=0,j=0;
        int maxm = INT_MIN;
        while(j<n){
            sum += nums[j];
            maxm = max(maxm, sum);
            
            if(sum<0){
                sum = 0;
                i = j+1;
            }
            j++;
        }
        if(maxm==INT_MIN)
            return sum;
        return maxm;
    }
};