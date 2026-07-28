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
    vector<string> paths;
public:
    void preorder(TreeNode* current, string path) {
        if(!current) return;
        path += to_string(current->val) + "->";
        if(!current->left && !current->right) {
            path.pop_back(); path.pop_back();
            paths.push_back(path);
        }
        preorder(current->right, path);
        preorder(current->left, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root, "");
        return paths;
    }
};