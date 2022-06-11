class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cntzero = 0;
        int cnteven = 0;
        int ans = 0;
        while(cntzero!=n){
            cntzero = 0;
            for(int i=0;i<n;i++){
                
                if(nums[i]%2!=0){
                    nums[i]--;
                    ans++;
                }
                if(nums[i]==0) cntzero++;
            }
            if(cntzero==n) break;
            else{
                for(int i=0;i<n;i++){
                    nums[i] /= 2;
                }
                ans++;
            }
            
        }
        return ans;
    }
};