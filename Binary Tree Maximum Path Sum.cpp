class Solution {
public:
    int dfs(TreeNode* root,int &res){
        if(root==NULL) return 0;
        int left = max(0,dfs(root->left,res));
        int right = max(0,dfs(root->right,res));
        res = max(res,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
};
