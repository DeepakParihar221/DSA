class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> prefix(n, 0);
        prefix[0] = chalk[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+chalk[i];
        }
        int rem = k%prefix[n-1];
        if(rem==0) return 0;
        int index = 0;
        for(int i=0;i<n;i++){
            if(rem<prefix[i]) return i%n;
        }
        return index;
    }
};