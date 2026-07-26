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
        TreeNode* last;
        TreeNode* mid;
        TreeNode* first;
        TreeNode* prev;
private:
    void dfs(TreeNode* root){
        if(root == NULL) return;
        
        dfs(root->left);

        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                mid = root;
            }
            else last = root;
        }
        prev = root;

        dfs(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        mid, first, last = NULL;
        dfs(root);
        if(last == NULL) swap(first->val, mid->val);
        else swap(first->val, last->val);
    }
};