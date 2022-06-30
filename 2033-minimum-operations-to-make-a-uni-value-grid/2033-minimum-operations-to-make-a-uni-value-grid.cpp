class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(auto i:grid){
            for(auto j:i){
                v.push_back(j);
            }
        }
        int n = v.size();
        nth_element(v.begin(), v.begin()+n/2, v.end());
        
        // for(auto i:v) cout<<i<<" ";
        
        int mid = v[n/2];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(abs(v[i]-mid)%x!=0)
                return -1;
            else
                cnt+=abs(v[i]-mid)/x; 
        }
        return cnt;
    }
};