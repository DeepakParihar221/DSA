class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = n/2;
        int des = nums[mid];
        int sum = 0;
        for(int num:nums){
            sum += abs(num-des);
        }
        return sum;
    }
};