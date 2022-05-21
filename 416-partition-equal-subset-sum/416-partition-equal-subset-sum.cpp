class Solution {
public:
    bool subsetSum(vector<int> nums, int n, int sum){
        bool a[n+1][sum+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
                a[i][j] = false;
        
        for(int i=0;i<=sum;i++)
            a[0][i] = false;
        for(int i=0;i<=n;i++)
            a[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j)
                    a[i][j] = a[i-1][j-nums[i-1]] || a[i-1][j];
                else
                    a[i][j] = a[i-1][j];
                
                // cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        return a[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i:nums)
            sum += i;
        if(sum%2!=0)
            return false;
         sum /= 2;
        return subsetSum(nums, n, sum);
    }
};