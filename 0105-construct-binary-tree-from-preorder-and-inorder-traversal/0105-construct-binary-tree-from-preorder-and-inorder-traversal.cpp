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
    int idx = 0;
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder, 0 , preorder.size() - 1);
        return root;
    }
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if (start > end) return nullptr; 

        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->left = helper(preorder, start, mid - 1);
        root->right = helper(preorder, mid + 1, end);

        return root;
    }
};