class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            vector<string> temp;
            for(auto product:products){
                int j = 0;
                while(j<=i && j<product.size()){
                    if(product[j]!=searchWord[j]) break;
                    j++;
                }
                if(j==i+1){
                    
                    temp.push_back(product);
                }
            }
            while(temp.size()>3) temp.pop_back();
            ans.push_back(temp);
        }
        return ans;
    }
};