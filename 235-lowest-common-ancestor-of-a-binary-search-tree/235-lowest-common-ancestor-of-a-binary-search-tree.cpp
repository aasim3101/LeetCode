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
    TreeNode* helper(TreeNode* node, TreeNode* p, TreeNode* q){
        if(p->val < node->val && q->val < node->val){
            return helper(node->left, p, q);
        }
        if(p->val > node->val && q->val > node->val){
            return helper(node->right, p, q);
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};