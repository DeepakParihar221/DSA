class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int count = 0;
        for(int i=0;i<n;++i){
            if(word[i]>='A' && word[i]<='Z')
                count++;
        }
        
        if(count==1 && word[0]>='A' && word[0]<='Z'){
            return true;
        }
        if(count==n || count==0)
            return true;
        
        return false;
    }
};