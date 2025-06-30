
class BSTIterator {
public:
    stack<TreeNode*> st;

    void fillStack(TreeNode* root){
        if(root==NULL) return;

        fillStack(root->right);
        st.push(root);
        fillStack(root->left);
    }
    BSTIterator(TreeNode* root) {
        fillStack(root); 
    }
    
    int next() {
        TreeNode* x=st.top();
        st.pop();
        return x->val;
    }
    
    bool hasNext() {
        return (st.empty()) ? false : true ; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
