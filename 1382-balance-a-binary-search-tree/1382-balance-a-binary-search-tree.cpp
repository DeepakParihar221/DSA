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
    void inorder(TreeNode* root, vector<int> &in){
        if(root==NULL) return;
        
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
        
        return;
    }
    TreeNode* solve(vector<int> &inorder, int l, int r){
        if(l>r) return NULL;
        
        int mid = (l+r)/2;
        TreeNode* bst = new TreeNode(inorder[mid]);
        bst->left = solve(inorder, l, mid-1);
        bst->right = solve(inorder, mid+1, r);
        
        return bst;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        TreeNode* bst = solve(in, 0, n-1);
        return bst;
    }
};