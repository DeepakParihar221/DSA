class Solution {
public:
    bool static comp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            temp.push_back(s);
        }
        sort(temp.begin(), temp.end(), comp);
        
        string ans = "";
        for(string s:temp) ans += s;
        if(ans[0]=='0') return "0";
        return ans;
    }
};