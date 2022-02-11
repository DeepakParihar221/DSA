class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> v(n, 0);
        int i=0;
        for(int k=0;k<n;++k){
            if(nums[k]<pivot){
                v[i++] = nums[k];
            }
        }
        for(int k=0;k<n;++k){
            if(nums[k]==pivot){
                v[i++] = nums[k];
            }
        }
        for(int k=0;k<n;++k){
            if(nums[k]>pivot){
                v[i++] = nums[k];
            }
        }
        return v;
    }
};