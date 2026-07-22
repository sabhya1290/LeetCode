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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int posIdx = n - 1;
        for(int i = 0; i < n; i++){
          mp[inorder[i]] = i;  
        }
        TreeNode* root = helper(postorder, 0, n - 1, posIdx);
        return root;
    }
    TreeNode* helper(vector<int>& postorder, int start, int end, int& posIdx){
        if(start > end) return nullptr;
        
        int rootVal = postorder[posIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->right = helper(postorder, mid + 1, end, posIdx);
        root->left = helper(postorder, start, mid - 1, posIdx);
        return root;
    }
};