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
    void paths(TreeNode* root, vector<string>& ans, string s){
        if(root == NULL) return;
        int val = root->val;
        if(root->left == NULL && root->right == NULL) s += to_string(val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s);
            return;
        }
        else s += to_string(val) + "->";
        paths(root->left, ans, s);
        paths(root->right, ans, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        paths(root, ans, s);
        return ans;
    }
};