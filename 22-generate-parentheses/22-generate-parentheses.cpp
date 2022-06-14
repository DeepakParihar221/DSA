class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, int n, int bal, string temp){
        //BASE
        if(open==n && close==n && bal==0){
            ans.push_back(temp);
            return;
        }
        if(bal<0) return;
        
        if(close==n)
        solve(open+1, close, n, bal+1, temp+'(');
        else if(open==n)
        solve(open, close+1, n, bal-1, temp+')');
        else{
            solve(open+1, close, n, bal+1, temp+'(');
            solve(open, close+1, n, bal-1, temp+')');
        }
        
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        
        solve(0, 0, n, 0, "");
        return ans;
    }
};