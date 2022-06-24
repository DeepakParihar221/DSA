class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.length();
        int lastnum = -1;
        for(int i=0;i<n;i++){
            int num = 0;;
            
            if(isdigit(s[i])){
                while(isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                if(lastnum>=num) return false;
                lastnum = num;
            }
        }
        return true;
    }
};