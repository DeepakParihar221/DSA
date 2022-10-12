class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstcol = false, firstrow = false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++) if(matrix[i][0]==0) firstrow = true;
        for(int j=0;j<m;j++) if(matrix[0][j]==0) firstcol = true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstrow){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
        if(firstcol){
            for(int j=0;j<m;j++)
                matrix[0][j] = 0;
        }
    }
};