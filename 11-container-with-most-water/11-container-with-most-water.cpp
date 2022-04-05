class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int i=0;
        int j=height.size()-1;
        while(i<=j)
        {
            int curr = (j-i)*(min(height[i],height[j]));
            area=max(area,curr);
            if(height[i]<height[j])
                i++;
            else
                j--;
            
        }
        
        return area;
    }
};