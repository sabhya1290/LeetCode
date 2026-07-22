class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return helper(postorder, inorderMap, 0, inorder.size() - 1, postIndex);
    }

private:
    TreeNode* helper(vector<int>& postorder, unordered_map<int, int>& inorderMap, int left, int right, int& postIndex) {
        if (left > right) return nullptr;
        
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderMap[rootVal];
        
        root->right = helper(postorder, inorderMap, mid + 1, right, postIndex);
        root->left = helper(postorder, inorderMap, left, mid - 1, postIndex);
        
        return root;
    }
};