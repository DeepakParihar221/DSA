class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();
        int i=0,j=0;
        int sum = 0;
        int avg = 0;
        int count = 0;
        while(j<n){
            
            if(j-i+1>k){
                sum -= nums[i++];
            }
            sum += nums[j];
            avg = sum/(j-i+1);
            if(j-i+1==k && avg>=threshold){
                count++;
            }
            j++;
        }
        
        return count;
    }
};