
class Solution {
  public:
    int size(Node* root){
        if(root==NULL) return 0;
        return 1+max(size(root->left),size(root->right));
    }
    bool isBalanced(Node* root) {
        if(root==NULL) return true;
        int l = size(root->left);
        int r = size(root->right);
        if(abs(l-r)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
