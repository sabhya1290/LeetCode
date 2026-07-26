/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Box {
public:
    bool bst;
    int sum;
    int max, min;

    Box() {
        bst = 1;
        sum = 0;
        max = INT_MIN;
        min = INT_MAX;
    }
};
class Solution {
public:
    Box* find(TreeNode* root, int& tsum) {
        if (!root)
            return new Box();

        Box* lh = find(root->left, tsum);
        Box* rh = find(root->right, tsum);

        if (lh->bst && rh->bst && lh->max < root->val && rh->min > root->val) {
            Box* head = new Box();
            head->sum = root->val + lh->sum + rh->sum;
            head->min = min(lh->min, root->val);
            head->max = max(rh->max, root->val);

            tsum = max(tsum, head->sum);
            return head;
        }

        else {
            Box* head = new Box();
            head->bst = 0;
            return head;
        }
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        find(root, sum);
        return sum;
    }
};