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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        deque<TreeNode*> dq;
        dq.push_front(root);
        bool left = true;
        while(!dq.empty()){
            int n = dq.size();
            vector<int> level;
            for(int i = 0; i < n; i++){
                TreeNode* t = dq.front();
                dq.pop_front();
                if(t->left != NULL) dq.push_back(t->left);
                if(t->right != NULL) dq.push_back(t->right);
                level.push_back(t->val);
            }
            if(left == false) reverse(level.begin(), level.end());
            if(left) left = false;
            else left = true;
            ans.push_back(level);
        }
        return ans;
    }
};