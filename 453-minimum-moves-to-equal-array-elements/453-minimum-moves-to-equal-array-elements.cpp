class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int minm = INT_MAX;
        for(int num:nums){
            minm = min(minm, num);
        }
        for(int num:nums){
            ans += num-minm;
        }
        return ans;
    }
};