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
    int maxm = 0;
    void solve(TreeNode* root, bool goLeft, int covered){
        if(root==NULL) return ;
        maxm = max(maxm, covered);
        if(goLeft){
            solve(root->left, false, covered+1);
            solve(root->right, true, 1);
        }
        else{
            solve(root->left, false, 1);
            solve(root->right, true, covered+1);
        }
        
        return;
    }
    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root, true, 0);
        solve(root, false, 0);
        
        return maxm;
    }
};