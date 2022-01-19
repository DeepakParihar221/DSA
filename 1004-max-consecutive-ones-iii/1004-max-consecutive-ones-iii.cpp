class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0,zeros=0,count=0,maxm=0;
        while(j<n){
            if(nums[j]==0){
                count++;
            }
            
            if(count<=k){
                maxm = max(maxm, j-i+1);
            }

            while(count>k){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return maxm;
    }
};