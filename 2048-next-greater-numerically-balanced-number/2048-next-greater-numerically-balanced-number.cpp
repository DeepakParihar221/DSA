class Solution {
public:
    int ans;
    int nextBeautifulNumber(int n) {
        int num = n;
        ans = 0;
        int firstdigit = 0;
        while(num>0){
            firstdigit = num/10;
            num /= 10;
        }
        int digit = n+1;
        
        while(1){
            vector<int> freq(10, 0);
            int number = digit;
            while(number>0){
                int rem = number%10;
                number /= 10;
                freq[rem]++;
            }
            int flag = 0;
            int cnt = 0;
            for(int i=1;i<10;i++){
                if(freq[0]!=0) break;
                if(freq[i]==i || freq[i]==0){
                    cnt++;
                }
                
                if(cnt==9){
                    flag = 1;
                    break;
                }
            }
            if(flag) return digit;
            digit++;
        }
        return ans;
    }
};