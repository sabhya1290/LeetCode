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
    unordered_map<int, int> inorder_map;
    int preorderIdx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i){
            inorder_map[inorder[i]] = i;
        }

        TreeNode* root = buildTreeHelper(preorder, 0, preorder.size() - 1);
        return root;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;

        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorder_map[rootVal];
        root->left = buildTreeHelper(preorder, left, mid - 1);
        root->right = buildTreeHelper(preorder, mid + 1, right);

        return root;
    }
};