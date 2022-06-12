class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 1;
        int bits = 0, res=0;
        for(int i=0;i<n;i++){
            bits = 0;
            while(nums[i]>0){
                res += nums[i]&1;
                bits++;
                nums[i] >>=1;
            }
            maxlen = max(maxlen, bits);
        }
        return maxlen-1+res;
    }
};