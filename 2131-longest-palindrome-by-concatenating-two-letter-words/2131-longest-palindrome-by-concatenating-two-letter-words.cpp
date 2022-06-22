class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        int cnt = 0;
        int flag = 0;
        for(auto word:words){
            if(word[0]==word[1]){
                if(m[word]>0){
                    cnt += 4;
                    m[word]--;
                    flag--;
                }
                else{
                    m[word]++;
                    flag++;
                }
                
            }
            else{
                string rev = string(word.rbegin(), word.rend());
                if(m[rev]>0){
                    cnt += 4;
                    m[rev]--;
                }
                else m[word]++;
            }
        }
        if(flag>0) cnt += 2;
        return cnt;
    }
};