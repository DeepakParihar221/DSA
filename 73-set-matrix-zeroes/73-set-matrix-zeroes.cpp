class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<pair<int, int>> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vec.push_back({i, j});
                }
            }
        }
        
        for(auto l:vec){
            int col=l.second, row=l.first;
            int k=0;
            while(k<n){
                matrix[k++][col] = 0;
            }
            k=0;
            while(k<m){
                matrix[row][k++] = 0;
            }
        }
    } 
};