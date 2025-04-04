class Solution {
    public:
        unordered_set<TreeNode*> st;
        int level;
        int levels(TreeNode* root){
            if(root==NULL) return 0;
            return 1+max(levels(root->left),levels(root->right));
        }
        void nthlevel(TreeNode* root,int curr,int level,unordered_set<TreeNode*>& st){
        if(root==NULL) return;
        if(curr==level){
            st.insert(root);
            return;
        }
        nthlevel(root->left,curr+1,level,st);
        nthlevel(root->right,curr+1,level,st);
       }
       bool inorder(TreeNode* root){
        if(root==NULL) return false;
        if(st.find(root)!=st.end()) return true;
        return inorder(root->left) || inorder(root->right);
       }
       TreeNode* helper(TreeNode* root){
        if(root==NULL) return NULL;
        if(st.find(root)!=st.end()) return root;
        bool left = inorder(root->left);
        bool right = inorder(root->right);
        if(left==true && right==true) return root;
        if(left==true) return helper(root->left);
        return helper(root->right);
       }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            level = levels(root);
            nthlevel(root,1,level,st);
            
            return helper(root);
        }
    };//1123