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
        // string s="";
        // if(root==nullptr) {
        //     return s+="N,";
        // }
        // return s+=to_string(root->val)+","+ s+=serialize(root->left)+ s+=serialize(root->right);        
        if(root==nullptr) return"";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node==nullptr){
                    s+="N,";
                    continue;
                }
                else s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    // TreeNode* helper(string &data) {
    //     // int pos=data.find(",");
    //     // string val=data.substr(0,pos);
    //     // data.erase(0,pos+1);
    //     // if(val=="N") return nullptr;
    //     // TreeNode* root=new TreeNode(stoi(val));
    //     // root->left=helper(data);
    //     // root->right=helper(data);
    //     // return root;
    //  }
    TreeNode* deserialize(string data){
        // return helper(data);
        if(data.size()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                getline(s,str,',');
                if(str=="N"){
                    node->left=nullptr;
                }
                else{
                    TreeNode* lefts=new TreeNode(stoi(str));
                    node->left=lefts;
                    q.push(lefts);
                }

                getline(s,str,',');
                if(str=="N"){
                    node->right=nullptr;
                }
                else{
                    TreeNode* rights=new TreeNode(stoi(str));
                    node->right=rights;
                    q.push(rights);
                }

            }
        }
        return root;


}
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;