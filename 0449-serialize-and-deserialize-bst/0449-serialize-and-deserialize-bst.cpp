class Codec {
public:

    // Serialize using preorder traversal
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<int> preorder;
        stringstream ss(data);
        int x;
        while (ss >> x)
            preorder.push_back(x);

        int idx = 0;
        return build(preorder, idx, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int &idx, int low, int high) {
        if (idx == preorder.size())
            return NULL;

        int val = preorder[idx];

        if (val < low || val > high)
            return NULL;

        TreeNode* root = new TreeNode(val);
        idx++;

        root->left = build(preorder, idx, low, val);
        root->right = build(preorder, idx, val, high);

        return root;
    }
};