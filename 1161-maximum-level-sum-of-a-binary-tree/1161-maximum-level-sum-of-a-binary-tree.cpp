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
    int maxLevelSum(TreeNode* root) {
        vector<long> sum(150, 0);
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        long maxm = LONG_MIN;
        int index = 0;
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum[level] += temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(maxm<sum[level]){
                maxm = sum[level];
                index = level;
            }
            level++;
        }
        return index;
    }
};