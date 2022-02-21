class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int count = 1,maxm = 0;
        
//         return nums[n/2];
        int count = 0;
        int a = nums[0];
        for(int i=0;i<n-1;++i){
            if(nums[i]==a) count++;
            else count--;
            
            if(count==0){
                a = nums[i+1];
            }
        }
        
        return a;
    }
};