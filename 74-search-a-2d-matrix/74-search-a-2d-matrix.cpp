class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m*n-1;
        while(r>=l){
            int mid = (l+r)/2;
            if(matrix[mid/m][mid%m]==target)
                return true;
            
            if(matrix[mid/m][mid%m]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};