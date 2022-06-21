class Solution {
public:
    int minDeletions(string s) {
        set<int> freq;
        int n = s.length();
        if(n==0 || n==1) return n;
        int deleted = 0;
        sort(s.begin(), s.end());
        
        for(int i=0;i<n-1;i++){
            int cnt = 1;
            while(s[i]==s[i+1]){
                cnt++;
                i++;
            }
            
            if(freq.find(cnt)==freq.end()){
                freq.insert(cnt);
            }
            else{
                while(freq.find(cnt)!=freq.end()){
                    cnt--;
                    deleted++;
                }
                if(cnt>0)
                freq.insert(cnt);
            }
        }
        
        if(s[n-1]!=s[n-2]){
            if(freq.find(1)!=freq.end())
                deleted++;
        }
        return deleted;
    }
};