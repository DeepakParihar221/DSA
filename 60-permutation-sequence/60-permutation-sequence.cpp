class Solution {
public:
    int fact(int n){
        if(n==0 || n==1) return n;
        return n*fact(n-1);
    }
    string getPermutation(int n, int k) {
        vector<int> v;
        int num = 1;
        for(int i=1;i<=n;i++){
            num *= i;
            v.push_back(i);
        }
        num /= n;
        string st = "";
        k--;
        while(v.size()!=0){
            int index;
            if(num==0) index = 0;
            else index = k/num;
            st += to_string(v[index]);
            auto it = v.begin()+index;
            v.erase(it);
            if(v.size()==0) break;
            if(num==0) k = 0;
            else k = k%num;
            
            num /= v.size();
        }
        return st;
    }
};