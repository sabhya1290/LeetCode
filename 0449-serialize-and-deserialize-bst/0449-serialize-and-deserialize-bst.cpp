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
    void preorder(TreeNode* root,string& s){
        if(!root) return;
        
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) return s;
        preorder(root, s);
        return s;
    }
    int convertStringtoInt(string& data, int& pos){ // Find ',' and return value
        pos=data.find(',');
        int value=stoi(data.substr(0, pos));
        return value;
    }
    
    TreeNode* deserializehelper(string& data, int min, int max) {
        if(data.size()==0) return nullptr; 
        
        int pos=0;
        int value = convertStringtoInt(data, pos); 
        if (value < min || value > max) return nullptr; 
        
        TreeNode* tnode = new TreeNode(value); 
        data=data.substr(pos+1); 
        
        tnode->left=deserializehelper(data, min, tnode->val); 
        tnode->right=deserializehelper(data, tnode->val, max);
        return tnode;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        return deserializehelper(data, INT_MIN, INT_MAX);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;