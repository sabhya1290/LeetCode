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
    class BSTInfo {
    public:
        int mini;
        int maxi;
        int sum;
        bool isBST;

        BSTInfo(int mn, int mx, int s, bool bst) {
            mini = mn;
            maxi = mx;
            sum = s;
            isBST = bst;
        }
    };

    int maxSum = 0;

    BSTInfo largestBSTBT(TreeNode *root) {
        if (!root)
            return BSTInfo(INT_MAX, INT_MIN, 0, true);

        BSTInfo left = largestBSTBT(root->left);
        BSTInfo right = largestBSTBT(root->right);

        // Check if current subtree is BST
        if (left.isBST && right.isBST && left.maxi < root->val && right.mini > root->val) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return BSTInfo(min(left.mini, root->val),
                           max(right.maxi, root->val),
                           currSum, true);
        }

        // Not a BST
        return BSTInfo(INT_MIN, INT_MAX, 0, false);
    }

    int maxSumBST(TreeNode *root) {
        largestBSTBT(root);
        return maxSum;
    }
};