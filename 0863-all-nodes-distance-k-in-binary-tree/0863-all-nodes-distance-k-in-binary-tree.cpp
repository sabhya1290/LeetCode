/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParent(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left){
                parent_track[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent_track[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track, target);

        unordered_map<TreeNode* , bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int cr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(cr_level++ == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};