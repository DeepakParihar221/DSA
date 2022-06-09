class Solution {
public:
    int getBiggestPower(int num, int bound) {
        if (num == 1) return 1;
        int res = 0;
        while (bound) {
            bound /= num;
            res++;
        }
        return res;
    }
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int xx = getBiggestPower(x, bound), yy = getBiggestPower(y, bound);
        unordered_set<int> powerful;
        
        for (int i = 0; i <= xx; i++) {
            for (int j = 0; j <= yy; j++) {
                if (pow(x, i) + pow(y, j) <= bound) powerful.insert(pow(x, i) + pow(y, j));
            }
        }
        
        return vector<int>(powerful.begin(), powerful.end());
    }
};