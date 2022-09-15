/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || p==root || q==root) return root;
        
        TreeNode* l = lca(root->left, p, q);
        TreeNode* r = lca(root->right, p, q);
        
        if(l!=NULL && r!=NULL) return root;
        if(l==NULL) return r;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};