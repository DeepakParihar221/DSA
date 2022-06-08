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
    int solve(TreeNode* root, int &maxm){
        if(root==NULL) return 0;
        
        int l = solve(root->left, maxm);
        int r = solve(root->right, maxm);
        if(l<0) l=0;
        if(r<0) r=0;
        maxm = max(maxm, root->val+l+r);
        return root->val+max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int maxm = INT_MIN;
        solve(root, maxm);
        return maxm;
    }
};