class Solution {
public:
    void helper(int n, string &s){
        if(n>0)
            helper(n-1, s);

        if(n==1){
            s += "1";
            return;
        }
        
        string temp = "";
        int i = 0;
        for(i=0;i<s.length();++i){
            int count = 1;
            while(i<s.length()-1 && s[i]==s[i+1]){
                count++;
                i++;
            }
            temp += to_string(count);
            temp += s[i];
        }
        s = temp;
        return;
    }
    string countAndSay(int n) {
        string s = "";
        helper(n , s);
        return s;
    }
};