class Solution {
public:
    int minPartitions(string s) {
        int maxm = 0;
        int n = s.length();
        for(int i=0;i<n;++i){
            int num = s[i]-'1'+1;
            maxm = max(maxm, num);
        }
        return maxm;
    }
};