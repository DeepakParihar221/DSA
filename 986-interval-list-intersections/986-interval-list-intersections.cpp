class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstlist, vector<vector<int>>& secondlist) {
        vector<vector<int>> ans;
        int n = firstlist.size();
        int m = secondlist.size();
        int i=0, j=0;
        while(i<n && j<m){
            int start = max(firstlist[i][0], secondlist[j][0]);
            int end = min(firstlist[i][1], secondlist[j][1]);
            vector<int> temp = {start, end};
            if(secondlist[j][1]>firstlist[i][1]) i++;
            else if(firstlist[i][1]>secondlist[j][1]) j++;
            else{
                i++;
                j++;
            }
            if(end>=start)
            ans.push_back(temp);
        }
        
        return ans;
    }
};