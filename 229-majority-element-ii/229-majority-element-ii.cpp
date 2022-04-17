class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
            else if(c1==0){
                c1 = 1;
                num1 = nums[i];
            }
            else if(c2==0){
                c2 = 1;
                num2 = nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        if(num1==num2){
            ans.push_back(num1);
            return ans;
        }
        
        int fcount1 = 0, fcount2 = 0;
        for(int i=0;i<n;i++){
            if(num1==nums[i]) fcount1++;
            if(num2==nums[i]) fcount2++;
        }
        
        if(fcount1>n/3) ans.push_back(num1);
        if(fcount2>n/3) ans.push_back(num2);
        
        return ans;
    }
};