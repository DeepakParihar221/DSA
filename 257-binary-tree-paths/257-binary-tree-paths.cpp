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
    void solve(TreeNode* root, string path, vector<string>& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        
        path += to_string(root->val);
        path += "->";
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        // path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        solve(root, path, ans);
        return ans;
    }
};