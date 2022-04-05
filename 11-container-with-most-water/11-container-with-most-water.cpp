class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int maxarea = 0;
        while(i!=j){
            maxarea = max(min(height[i], height[j])*(j-i), maxarea);
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};