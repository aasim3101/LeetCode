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
    map<int,int> mp;
    int ind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder, 0, n-1);
    }
    TreeNode* helper(vector<int> &preorder, int left, int right){
        if(left > right){
            return NULL;
        }
        int rootVal = preorder[ind++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(preorder, left, mp[rootVal]-1);
        root->right = helper(preorder, mp[rootVal]+1, right);
        return root;
    }
};