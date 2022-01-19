class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.length();
        if(n==1 || n==0)
            return n;
            
        int i=0,j=0,maxm=0;
        int count[2] = {0};
        int maxfreq = 0;
        while(j<n){
            if(s[j]=='T'){
                count[0]++;
                maxfreq = max(maxfreq, count[0]);
            }
            else{
                count[1]++;
                maxfreq = max(maxfreq, count[1]);
            }
            
            if(j-i+1<=k+maxfreq){
                maxm = max(j-i+1, maxm);
            }
            if(j-i+1>k+maxfreq){
                if(s[i]=='T')
                    count[0]--;
                else
                    count[1]--;
                    
                i++;
            }
            
            j++;
        }
        return maxm;
    }
};