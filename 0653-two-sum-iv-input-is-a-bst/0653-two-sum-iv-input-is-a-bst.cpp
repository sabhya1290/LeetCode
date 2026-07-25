
class Solution {
public:
    bool twoSum(vector<int>& order, int k){
        
        int l = 0;
        int h = order.size()-1;

        while(l<h){
          if(order[l] + order[h] == k){
            return true;
          }else if(order[l] + order[h] > k){
              h--;
          }else{
              l++;
          }
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int>& order){

        if(!root) return;

        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>order;
        inorder(root, order);
        
        // int res = INT_MAX;
        // int n = order.size();

        // for(int i = 1; i<n; i++){
        //     res = min(res, (order[i]-order[i-1]));
        // }
       return twoSum(order, k);
    }
};