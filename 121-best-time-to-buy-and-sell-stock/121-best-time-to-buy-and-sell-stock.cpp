class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = INT_MAX;
        int ans = 0;
        
        int n = prices.size();
        for(int i=0;i<n;++i){
            minm = min(minm, prices[i]);
            
            ans = max(prices[i] - minm, ans);
        }
        return ans;
    }
};