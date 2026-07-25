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
private:
    void preorder(TreeNode* root, int k, unordered_set<int>& mp, bool& ans){
        if(root == NULL )return;
        if (mp.count(root->val)) {
            ans = true; return;
        }
        else{
            mp.insert(k - root->val);
        }
        preorder(root->left, k, mp, ans);
        preorder(root->right, k, mp, ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> mp;
        bool ans = false;
        preorder(root, k, mp, ans);
        return ans;
    }
};