class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int i = 0; int j = 0; int localMaxFreq = 0; 
        for(j=0; j<size; j++){
            count[s[j]-'A']++;
            localMaxFreq = max(localMaxFreq, count[s[j]-'A']);
            
            if((j-i+1)-localMaxFreq == k)
                ret = max(j-i+1, ret);
            
            if((j-i+1)-localMaxFreq > k)
                count[s[i++]-'A']--;
        }
        return max(ret, j-i);
    }
};