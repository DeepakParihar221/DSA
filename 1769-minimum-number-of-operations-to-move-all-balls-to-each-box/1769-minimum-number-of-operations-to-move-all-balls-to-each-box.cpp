class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v, ans;
        int n = boxes.length();
        for(int i=0;i<n;++i){
            if(boxes[i]=='1')
                v.push_back(i);
        }
        
        for(int i=0;i<n;++i){
            int sum = 0;
            for(int j=0;j<v.size();++j){
                sum += abs(v[j]-i);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};