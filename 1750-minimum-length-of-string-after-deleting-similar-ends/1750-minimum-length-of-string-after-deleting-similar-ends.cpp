class Solution {
public:
    bool isPalindrome(string s){
        int l = 0, r = s.length()-1;
        while(l<=r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
    int minimumLength(string s) {
        
        int l = 0, r = s.length()-1;
        while(l<r){
            char c = s[l];
            if(s[l]==s[r]){
                while(s[l]==s[l+1] && l+1<r){
                    l++;
                }
                l++;
                while(s[r]==s[r-1] && l+1<r){
                    r--;
                }
                r--;
            }
            if(s[l]!=s[r]) break;
        }
        return r-l+1;
    }
};