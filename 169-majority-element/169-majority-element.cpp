class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int votes = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i]==candidate){
                votes++;
            }
            else{
                votes--;
            }
            if(votes==0){
                candidate = nums[i];
                votes = 1;
            }
        }
        return candidate;
    }
};