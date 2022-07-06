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
    bool inorder(TreeNode* node, int k, unordered_set<int> &st){
        if(node == NULL){
            return false;
        }
        if(inorder(node->left, k, st)){
            return true;
        }
        if(st.find(k-node->val) != st.end()){
            return true;
        }
        st.insert(node->val);
        if(inorder(node->right, k, st)){
            return true;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return inorder(root, k, st);
    }
};