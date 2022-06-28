class Solution {
public:
    bool static comp(pair<int,int> a, pair<int,int> b){
        if(a.second<b.second) return true;
        return false;
    }
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        //          <num, freq>
        map<int, int> m;
        for(int num:nums){
            m[num]++;
            // cout<<v[num]<<" ";
        }
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back(i);
        }
        sort(v.begin(), v.end(), comp);
        for(auto &i:v){
            if(k>0){
                k -= i.second;
                if(k>=0){
                    i.second = 0;
                }
            }
        }
        int cnt = 0;
        for(auto i:v){
            if(i.second!=0) cnt++;
        }
        return cnt;
    }
};