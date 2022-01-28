/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void util(TreeNode* root, int level, vector<vector<int>> &ans){
        if(root==NULL)
            return;
        
        if(ans.size() == level)
        ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        util(root->left, level+1, ans);
        util(root->right, level+1, ans);
        
        return;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> ans;
        util(root, 0, ans);
        
        return ans[ans.size()-1][0];
    }
};