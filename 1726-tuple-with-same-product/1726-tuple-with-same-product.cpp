class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                m[nums[i]*nums[j]]++;
            }
        }
        // for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
        int count = 0;
        for(auto i:m){
            if(i.second>1){
                count += (i.second*(i.second-1))/2;
            }
        }
        
        return count*8;
    }
};