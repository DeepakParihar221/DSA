class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int i=0,j=0;
        int vowel = 0;
        int maxm = 0;
        while(j<n){
            if(j-i+1<=k){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    vowel++;
                }
                maxm = max(maxm, vowel);
                j++;
            }
            else{
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                    vowel--;
                }
                if(vowel<0) vowel = 0;
                i++;
            }
        }
        return maxm;
    }
};