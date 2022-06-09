class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==k)
        return "0";
        stack<char> s;
        
        for(char c:num){
            while(!s.empty() && k>0 && s.top()>c){
                s.pop();
                k--;
            }
            if(s.empty() && c=='0') continue;
            else s.push(c);
        }
        
        while(!s.empty() && k>0){
            s.pop();
            k--;
            if(s.empty()) return "0";
        }
        string res = "";
        if(s.empty()) return "0";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};