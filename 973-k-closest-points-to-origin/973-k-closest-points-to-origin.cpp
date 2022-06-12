class Solution {
public:
    int squaredDistance(vector<int> &point){
        return (point[0]*point[0])+(point[1]*point[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++){
            pair<int, int> entry;
            entry = {squaredDistance(points[i]), i};
            if(pq.size()<k){
                pq.push(entry);
            }
            else if(pq.top().first>entry.first){
                pq.pop();
                pq.push(entry);
            }
        }
        
        while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};