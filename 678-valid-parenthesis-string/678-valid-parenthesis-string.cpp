class Solution {
public:
    int dp[101][101];
    bool solve(string &s, int bal, int index){
        if(bal<0){
            return false;
        }
        if(index>=s.length()){
            if(bal!=0)
                return false;
            return true;
        }
        if(dp[index][bal]!=-1) return dp[index][bal];
        bool l = false, r = false, sp = false;
        if(s[index]=='(')
        l = solve(s, bal+1, index+1);
        else if(s[index]==')')
        r = solve(s, bal-1, index+1);
        else{
            l = solve(s, bal+1, index+1);
            r = solve(s, bal-1, index+1);
            sp = solve(s, bal, index+1);
        }
        
        
        return dp[index][bal] = l||r||sp;
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        bool ans = solve(s, 0, 0);
        return ans;
    }
};