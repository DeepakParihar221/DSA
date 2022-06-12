class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxm = 0;
        int i=0, j=0;
        map<int, int> m;
        while(j<n){
            m[nums[j]]++;
            sum += nums[j];
            
            if(j-i+1>m.size()){
                while(j-i+1>m.size()){
                    m[nums[i]]--;
                    sum -= nums[i];
                    if(m[nums[i]]==0){
                        m.erase(nums[i]);
                    }
                    i++;
                }
            }
            else if(j-i+1==m.size()){
                if(sum>maxm) maxm = sum;
            }
            j++;
            
        }
        return maxm;
    }
};