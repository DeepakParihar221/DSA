class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        // for(int i=0;i<n;i++)
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        
        for(int i=0;i<n;i++){
            int minm = intervals[i][0];
            int maxm = intervals[i][1];
            while(i+1<n && maxm>=intervals[i+1][0]){
                i++;
                maxm = max(intervals[i][1], maxm);
            }
            ans.push_back({minm, maxm});
        }
        return ans;
    }
};