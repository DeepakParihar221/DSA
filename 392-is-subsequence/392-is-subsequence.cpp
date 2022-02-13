class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int n = s.length();
        if(t.length()==0 && n==0)
            return true;
        for(char c:t){
            if(s[i]==c)
                i++;
            if(i==n)
                return true;
        }
        return false;
    }
};