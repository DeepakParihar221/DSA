class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxm = 0;
        int n = accounts.size();
        int m = accounts[0].size();
        int sum = 0;
        for(int i=0;i<n;++i){
            sum = 0;
            for(int j=0;j<m;++j){
                sum += accounts[i][j];
            }
            maxm = max(sum, maxm);
        }
        return maxm;
    }
};