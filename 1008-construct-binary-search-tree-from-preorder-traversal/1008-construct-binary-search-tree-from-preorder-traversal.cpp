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
    TreeNode* helper(vector<int>& A , int& i, int b){
        int n = A.size();
        if(i == n || A[i] > b) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = helper(A, i, root->val);
        root->right = helper(A, i, b);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};