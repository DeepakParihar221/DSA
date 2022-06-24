class Solution {
public:
    string sortSentence(string s) {
        vector<string> store(10);
        string temp = "";
        for(char c:s){
            
            if(c==' '){
                int n = temp.size();
                int index = temp[n-1]-'0';
                store[index] = temp;
                temp = "";
                continue;
            }
            temp += c;
        }
        int n = temp.size();
        int index = temp[n-1]-'0';
        store[index] = temp;
        string res = "";
        for(auto i:store){
            if(i.length()>0){
                for(char c:i){
                    if(isdigit(c)) continue;
                    res += c;
                }
                res += " ";
            }
            
        }
        res.pop_back();
        return res;
    }
};