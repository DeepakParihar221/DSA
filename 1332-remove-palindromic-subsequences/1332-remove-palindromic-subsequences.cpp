class Solution {
public:
    bool isPalindrome(string s, int n){
        int start = 0, end=n-1;
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        int n = s.size();
        bool pal = isPalindrome(s, n);
        if(pal) return 1;
        return 2;
    }
};