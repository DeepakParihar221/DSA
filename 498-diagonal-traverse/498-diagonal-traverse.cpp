class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        vector<vector<int>> res(max(2*n+1, n+m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)%2==0){
                    res[i+j].insert(res[i+j].begin(), mat[i][j]);
                }
                else
                    res[i+j].push_back(mat[i][j]);
            }
        }
        
        for(auto i:res){
            for(auto j:i){
                ans.push_back(j);
            }
        }
        return ans;
    }
};