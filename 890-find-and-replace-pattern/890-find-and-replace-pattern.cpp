class Solution {
public:
    bool match(string word, string pattern){
        map<char, char> m1;
        map<char, char> m2;
        
        for(int i=0;i<word.length();i++){
            char p = pattern[i];
            char w = word[i];
            
            if(m1.find(w)==m1.end()) m1[w] = p;
            if(m2.find(p)==m2.end()) m2[p] = w;
            
            if(m1[w]!=p || m2[p]!=w) return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word:words){
            if(word.length()!=pattern.length()) continue;
            if(match(word, pattern)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};