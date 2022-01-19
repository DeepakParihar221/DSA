class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int i = 0; int j = 0; int localMaxFreq = 0; 
        for(; j<size; j++){
            count[s[j]-'A']++;
            localMaxFreq = max(localMaxFreq, count[s[j]-'A']);
            if((j-i+1)-localMaxFreq > k) {
                ret = max(ret, (j-i));
                count[s[i]-'A']--;
                i++;
                // localMaxFreq = *(max_element(count.begin(), count.end()));
            }
        }
        return max(ret, j-i);
    }
};