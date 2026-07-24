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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == NULL) return node;
        TreeNode* search = root;
        while(true){
            if(search->val > val){
                if(search->left != NULL )search = search->left;
                else{search->left = node; break;}
            }
            else {
                if(search->right)search = search->right;
                else{search->right = node; break;}
            }
        }
        return root;
    }
};