class Solution {
public:
    //TC : O(nlogn)  SC : O(1)
    bool binarySearch(vector<vector<int>> matrix, int i, int target, int l, int r){
        if(r>=l){
            int mid = (l+r)/2;
            
            if(matrix[i][mid]==target)
                return true;
            
            if(matrix[i][mid]>target)
            return binarySearch(matrix, i, target, l, mid-1);
            else
            return binarySearch(matrix, i, target, mid+1, r);
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        bool index = false;
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
            index = binarySearch(matrix, i, target, 0, m-1);
            }
        }
        return index;
    }
};