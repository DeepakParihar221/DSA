class Solution {
public:
    int stoneGameVI(vector<int>& aval, vector<int>& bval) {
        priority_queue<pair<int, int>> pq;
        int n = aval.size();
        for(int i=0;i<n;i++){
            pq.push({aval[i]+bval[i], i});
        }
        int ascore = 0, bscore = 0;
        int i=0;
        while(!pq.empty()){
            if(i%2==0) ascore += aval[pq.top().second];
            else bscore += bval[pq.top().second];
            i++;
            pq.pop();
        }
        
        if(ascore==bscore) return 0;
        
        return ascore>bscore?1:-1;
    }
};
