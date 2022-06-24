class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        reverse(nums2.begin(), nums2.end());
        int maxm = 0;
        for(int i=0;i<n;i++){
            int index = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            index = nums2.size()-1-index;
            // cout<<index<<endl;
            maxm = max(maxm, index-i);
        }
        return maxm;
    }
};