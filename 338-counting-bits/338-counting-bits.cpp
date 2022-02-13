class Solution {
public:
    vector<int> countBits(int n) {
        int num = 0;
        vector<int> dp;
        dp.push_back(0);
        int i=0,j=0;
        int size;
        while(j<n){
            size = dp.size();
            while(j<n && i<size){
                dp.push_back(dp[i]+1);
                i++;
                j++;
            }
            i = 0;
        }
        return dp;
    }
};