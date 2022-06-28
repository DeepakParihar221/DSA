class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]>0 || st.empty()){
                st.push(nums[i]);
            }
            else if(nums[i]<0){
                int val = nums[i]*-1;
                while(!st.empty() && st.top()>0 && st.top()<val){
                    st.pop();
                }
                if(st.empty() || st.top()<0) st.push(nums[i]);
                else if(st.top()==val) st.pop();
            }
            
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        
        return ans;
    }
};