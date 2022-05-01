class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0, j=0, maxm = 0;
        map<char, int> m;
        while(j<n){
            m[s[j]]++;
            if(j-i+1==m.size()){
                maxm = max(maxm, j-i+1);
            }
            else if(j-i+1>m.size()){
                while(j-i+1>m.size()){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxm;
    }
};