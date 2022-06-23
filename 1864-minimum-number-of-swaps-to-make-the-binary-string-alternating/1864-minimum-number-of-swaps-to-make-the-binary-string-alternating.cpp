class Solution {
public:
    int minSwaps(string s) {
        int cnt0 = 0, cnt1 = 0;
        for(char c:s){
            if(c=='0') cnt0++;
            else cnt1++;
        }
        int bal = abs(cnt1-cnt0);
        if(bal>1) return -1;
        int n = s.size();
        string res;
        string res1 = "";
        string res2 = "";
        int swaps = 0;
        int c0 = cnt0, c1 = cnt1;
        if(cnt1>cnt0){
            while(c1 && c0){
                res += "10";
                c1--;
                c0--;
            }
            res += "1";
        }
        else if(cnt1<cnt0){
            while(c1 && c0){
                res += "01";
                c1--;
                c0--;
            }
            res += "0";
        }
        else{
            while(c1 && c0){
                res1 += "10";
                c1--;
                c0--;
            }
            c1 = cnt1, c0 = cnt0;
            while(c1 && c0){
                res2 += "01";
                c1--;
                c0--;
            }
        }
        if(res.size()){
            for(int i=0;i<n;i++){
                if(s[i]!=res[i]){
                    swaps++;
                }
            }
        }
        else{
            int s1 = 0, s2 = 0;
            for(int i=0;i<n;i++){
                if(s[i]!=res1[i]) s1++;
                if(s[i]!=res2[i]) s2++;
            }
            swaps = min(s1, s2);
        }
        
        return swaps/2;
    }
};