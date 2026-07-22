/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s += "#,";
            else s += to_string(node->val) + ",";
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!getline(ss, token, ',')) break;
            if (token != "#") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            if (!getline(ss, token, ',')) break;
            if (token != "#") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));