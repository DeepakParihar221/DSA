class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        while(1){
            if(nums[temp]==0){
                return temp;
            }
            else{
                int an = nums[temp];
                nums[temp] = 0;
                temp = an;
            }
        }
        return 0;
    }
};