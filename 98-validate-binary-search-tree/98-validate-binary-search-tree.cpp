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
    bool check(TreeNode* node, char ch, TreeNode* par, pair<long long,long long> range){
        if(node == NULL){
            return true;
        }
        if(node->val <= range.first || node->val >= range.second){
            return false;
        }
        bool ans1,ans2;
        ans1=check(node->left, ch, par, {range.first, node->val});
        ans2=check(node->right, ch, par, {node->val, range.second});
        return ans1 && ans2;
    }
    bool isValidBST(TreeNode* root) {
        return check(root->left, 'L', root, {-1000000000000, root->val}) && check(root->right, 'R', root, {root->val, 1000000000000});
    }
};