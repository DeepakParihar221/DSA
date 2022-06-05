class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s, int start, int end){
        if(start==end) return true;
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void solve(string s, vector<string> temp, int index){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                solve(s, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp, 0);
        return ans;
    }
};