class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.length();
        int cnt = 1;
        int maxlen = 0;
        int len = 0;
        vector<string> temp;
        string st = "";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                cnt++;
                len = 0;
                temp.push_back(st);
                st = "";
            }
            else{
                len++;
                st += s[i];
            }
            
            maxlen = max(len, maxlen);
        }
        temp.push_back(st);
        
        
        int maxm = 0;
        for(string a:temp){
            int l = a.length();
            maxm = max(maxm, l);
        }
        vector<string> ans(maxm);
        for(string a:temp){
            for(int i=0;i<maxm;i++){
                if(a.length()-1<i){
                    ans[i].push_back(' ');
                }
                else{
                    ans[i].push_back(a[i]);
                }
            }
        }
        int i = 0;
        for(string a:ans){
            int len = a.size()-1;
            while(a[len]==' '&&len>0){
                len--;
            }
            int size = a.size();
            string subst = a.substr(0, len+1);
            ans[i] = subst;
            i++;
        }
        
        return ans;
    }
};