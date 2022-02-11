class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        
        map<int, int> m;
        for(int i=0;i<n;++i){
            m[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();++i){
            if(m[nums[i]]==1 && m.find(nums[i]-1)==m.end() && m.find(nums[i]+1)==m.end())
                v.push_back(nums[i]);
        }
        
        return v;
    }
};