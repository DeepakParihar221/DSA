class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count[3] = {0, 0, 0};
        int i=0,j=0;
        int ans = 0;
        while(j<n){
            count[s[j]-'a']++;
            while(count[0]&&count[1]&&count[2]){
                count[s[i]-'a']--;
                i++;
            }
            ans += i;
            j++;
        }
        return ans;
    }
};