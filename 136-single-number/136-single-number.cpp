class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
        int res = a[0];
        for(int i=1;i<n;++i){
            res ^= a[i];
        }
        return res;
    }
};