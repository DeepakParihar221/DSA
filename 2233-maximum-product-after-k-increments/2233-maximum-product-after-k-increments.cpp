class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<n;i++) pq.push(nums[i]);
        
        while(k>0){
            int num = pq.top();
            pq.pop();
            while(num<=pq.top() && k>0){
                num++;
                k--;
            }
            pq.push(num);
        }
        long prod = 1;
        while(!pq.empty()){
            prod = (prod*pq.top())%1000000007;
            pq.pop();
        }
        return (int)prod;
    }
};