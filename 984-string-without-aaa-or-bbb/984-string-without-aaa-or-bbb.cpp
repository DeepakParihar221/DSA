class Solution {
public:
    string ret;
    void solve(string ans, int a, int b){
        if(a==0 && b==0){
            ret = ans;
            return ;
        }
        if(a==0){
            solve(ans+'b', a, b-1);
        }
        else if(b==0){
            solve(ans+'a', a-1, b);
        }else if(a>b){
            ans.append("aab");
            solve(ans, a-2, b-1);
        }
        else if(b>a){
            ans.append("bba");
            solve(ans, a-1, b-2);
        }
        else if(a==b){
            ans.append("ab");
            solve(ans, a-1, b-1);
        }
        
        return;
    }
    string strWithout3a3b(int a, int b) {
        string ans = "";
        ret = "";
        solve(ans, a, b);
        return ret;
    }
};