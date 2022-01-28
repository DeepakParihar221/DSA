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
    void helper(TreeNode* root, vector<vector<int>> &ans, int level){
        if(root==NULL)
            return;
        
        if(ans.size()==level)
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        helper(root->left, ans, level+1);
        helper(root->right, ans, level+1);
        
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, ans, 0);
        
        for(int i=0;i<ans.size();++i)
            v.push_back(ans[i][ans[i].size()-1]);
        
        return v;
    }
};