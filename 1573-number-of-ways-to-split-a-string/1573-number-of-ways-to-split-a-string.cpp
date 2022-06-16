class Solution {
public:
    int numWays(string s) {
        int ones = 0;
        for(char c:s){
            if(c=='1') ones++;
        }
        
        if(ones%3!=0) return 0;
        int n = s.size();
        long long temp;
        if(n%2==0) 
        temp = (long long)((n-2)/2)*(n-1);
        else 
        temp = (long long)((n-1)/2)*(n-2);
        int tempres = (int)(temp%1000000007);
        if(ones==0) return tempres;
        
        ones /= 3;
        long long nl = 0, nr = 0;
        long long lones = 0;
        for(char c : s){
            if(c=='1'){
                lones++;
            }
            
            if(lones==ones){
                nl++;
            }
            else if(lones==2*ones){
                nr++;
            }
        }
        
        long long ans = (long long)(nl*nr);
        int res = (int)(ans%1000000007);
        return res;
    }
};