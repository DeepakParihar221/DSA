class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        int cnt = 0;
        int extra = 0;
        for(char c:s){
            if(m[c]>0){
                m[c]--;
                cnt += 2;
                extra--;
            }
            else{ 
                m[c]++;
                extra++;
            }
        }
        
        if(extra>0) cnt += 1;
        
        return cnt;
    }
};