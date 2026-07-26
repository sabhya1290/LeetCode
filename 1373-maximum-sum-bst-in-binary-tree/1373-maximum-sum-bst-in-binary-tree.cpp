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
class Node{
    public: 
        int mx,mn,sum;
    Node(int mn,int mx, int sum){
        this->mx = mx;
        this->mn = mn;
        this->sum = sum;
    }
};
class Solution {
public:
    int ans = 0;
    Node helper(TreeNode* root){
        if(!root) return Node(INT_MAX, INT_MIN,0);
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.mx< root->val && right.mn > root->val){
            int cursum = left.sum + right.sum + root->val;
            ans = max(ans, cursum);
            return Node(min(root->val, left.mn),max(root->val,right.mx),cursum);
        }
        return Node(INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};