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
    void helper(TreeNode* root, vector<int> &v, int curr){
        if(root==NULL)
            return;
        
        curr = curr*10+root->val;
        if(root->left==NULL && root->right==NULL){
            v.push_back(curr);
            return;
        }
        
        helper(root->left, v, curr);
        helper(root->right, v, curr);
        
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<int> v;
        helper(root, v, 0);
        
        int sum = 0;
        for(int i=0;i<v.size();++i)
            sum += v[i];
        
        return sum;
    }
};