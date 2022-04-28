class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1)
            return n;
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        
        int maxm = 0;
        for(int i=0;i<n;i++){
            //TODO here only
            if(s.find(nums[i]-1)==s.end()){
                int count = 0;
                int num = nums[i];
                while(s.find(num)!=s.end()){
                    count++;
                    num++;
                }
                maxm = max(maxm, count);
            }
            
        }
        
        return maxm;
    }
};