class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        
        int i=0,j=n-1;
        while(a[i]+a[j]!=target){
            if((a[i]+a[j])>target) j--;
            else if((a[i]+a[j])==target) break;
            else i++;
        }
        return {i+1, j+1};
    }
};