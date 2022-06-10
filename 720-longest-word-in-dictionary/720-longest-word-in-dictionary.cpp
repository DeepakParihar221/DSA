class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> s;
        string ans = "";
        for(auto i:words){
            string temp = i.substr(0, i.size()-1);
            if(i.size()==1 || s.find(temp)!=s.end()){
                s.insert(i);
                if(ans.size()<i.size())
                ans = i;
            }
        }
        return ans;
    }
};