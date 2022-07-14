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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        map<int,int> mp;
        int n=preorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        for(int i=1; i<n; i++){
            TreeNode* curr_root=root;
            TreeNode* temp = new TreeNode(0);
            int value=curr_root->val;
            if(mp[preorder[i]] < mp[value]){
                temp=curr_root->left;
            }
            else{
                temp=curr_root->right;
            }
            while(temp != NULL){
                curr_root=temp;
                value=curr_root->val;
                if(mp[preorder[i]] < mp[value]){
                    temp=curr_root->left;
                }
                else{
                    temp=curr_root->right;
                }
            }
            if(mp[preorder[i]] < mp[value]){
               curr_root->left=new TreeNode(preorder[i]);
            }
            else{
                curr_root->right = new TreeNode(preorder[i]);
            }
        }
        return root;
        // TreeNode* root = new TreeNode(1);
        // TreeNode* temp = root->left;
        // if(temp == NULL){
        //     cout<<"yes";
        // }
        // else cout<<"NO";
        // return temp;
    }
};