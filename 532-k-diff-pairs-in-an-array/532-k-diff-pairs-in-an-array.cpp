class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        int n = a.size();
        if(n==1)
            return 0;
        sort(a.begin(), a.end());
        int count = 0;
        int i=0, j=1;
        // bool flag = false;
        while(j<n){
            
            while(j+1<n && a[j]==a[j+1]){
                j++;
            }
            
            if(j>i && abs(a[j]-a[i])==k){
                count++;
                j++;
                continue;
            }
            if(i<j && abs(a[j]-a[i])<k)
                j++;
            else if(i<j && abs(a[j]-a[i])>=k){
                i++;
                if(i==j)
                    j++;
            }
            
            
        }
        return count;
    }
};