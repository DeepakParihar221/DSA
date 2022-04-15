class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        string ans = "";
        bool carry = false;
        while(i>=0 && j>=0){
            if(b[j]=='1' && a[i]=='1'){
                if(!carry){ 
                    ans = "0" + ans;
                    carry = true;
                }
                else{
                    ans = "1" + ans;
                }
            }
            else if((b[j]=='0' && a[i]=='1') || (b[j]=='1' && a[i]=='0')){
                if(carry){
                    ans = "0"+ans;
                    
                }
                else{
                    ans = "1"+ans;
                }
            }
            else{
                if(carry){
                    ans = "1"+ans;
                    carry = false;
                }
                else{
                    ans = "0"+ans; 
                }
            }
            j--;
            i--;
        }
        
        while(i>=0){
            if(a[i]=='0'){
                if(carry){
                    ans = "1"+ans;
                    carry = false;
                }
                else{
                    ans = "0"+ans;
                }
            }
            else{
                if(carry){
                    ans = "0"+ans;
                }
                else{
                    ans = "1"+ans;
                }
            }
            i--;
        }
        while(j>=0){
            if(b[j]=='0'){
                if(carry){
                    ans = "1"+ans;
                    carry = false;
                }
                else{
                    ans = "0"+ans;
                }
            }
            else{
                if(carry){
                    ans = "0"+ans;
                }
                else{
                    ans = "1"+ans;
                }
            }
            j--;
        }
        
        if(carry){
            ans = "1"+ans;
        }
        
        return ans;
    }
};