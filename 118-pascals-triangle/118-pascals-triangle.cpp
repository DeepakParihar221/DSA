class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if(n==1)
            return {{1}};
        
        ans.push_back({1});
        ans.push_back({1,1});
        vector<int> last = {1,1};
        
        for(int i=3;i<=n;i++){
            vector<int> curr = {1};
            for(int j=0;j<last.size()-1;j++){
                curr.push_back(last[j]+last[j+1]);
            }
            curr.push_back(1);
            last = curr;
            ans.push_back(curr);
        }
        
        return ans;
    }
};