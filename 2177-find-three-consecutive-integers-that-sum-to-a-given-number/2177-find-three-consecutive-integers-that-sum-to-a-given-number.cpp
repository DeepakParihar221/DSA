class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0) return {};
        vector<long long> res;
        long long temp = num/3;
        res.push_back(temp-1);
        res.push_back(temp);
        res.push_back(temp+1);
        
        return res;
    }
};