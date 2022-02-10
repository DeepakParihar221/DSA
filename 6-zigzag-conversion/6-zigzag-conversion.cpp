class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<string> rows(min(n, numRows));
        if(numRows==1)
            return s;
        int currow = 0;
        int down = 1;
        for(int i=0;i<n;++i){
            rows[currow] += s[i];
            // cout<<currow<<" ";
            if(currow==numRows-1)
                down = 0;
            else if(currow==0)
                down = 1;
            
            if(down==1){
                currow += 1;
            }
            else
                currow -= 1;
            
        }
        string ans ;
        for(string st : rows){
            ans += st;
        }
        return ans;
    }
};