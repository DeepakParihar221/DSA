class Solution {
public:
    double champagneTower(int pour, int query_row, int query_glass) {
        if(pour==0) return 0;
        vector<vector<double>> ans;
        double poured = (double)pour;
        ans.push_back({poured});
        int row = 0;
        int qrow = query_row;
        while(query_row-->0){
            vector<double> temp;
            double t = (poured-1.0)/2.0;
            double maxm = max(t, 0.0);
            temp.push_back(maxm);
            for(int i=1;i<ans.size();i++){
                double l = max(ans[row][i-1]-1, 0.0);
                double r = max(ans[row][i]-1, 0.0);
                temp.push_back(max((l+r)/2, 0.0));
            }
            temp.push_back(maxm);
            poured = (poured-1.0)/2.0;
            row++;
            ans.push_back(temp);
        }
        for(auto i:ans){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return min(ans[qrow][query_glass], 1.0);
    }
};