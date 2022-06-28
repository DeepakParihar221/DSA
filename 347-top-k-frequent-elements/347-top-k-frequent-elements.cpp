class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        for(int num:nums) m[num]++;
        
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        int size = v.size()-1;
        int i=0;
        while(k>0){
            ans.push_back(v[size-i].second);
            k--;
            i++;
        }
        
        return ans;
    }
};