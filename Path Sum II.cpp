class Solution {
public:
    void helper(TreeNode* root,int &currSum, int targetSum,vector<int>& array,vector<vector<int>>& ans){
       if(root==NULL) return;
       array.push_back(root->val);
       currSum += root->val;
        if (!root->left && !root->right && targetSum == currSum) {
            ans.push_back(array);
        }
        helper(root->left,currSum, targetSum, array, ans);
        helper(root->right,currSum, targetSum, array, ans);
        currSum -= root->val;
        array.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> array;
        helper(root,sum,targetSum,array,ans);
        return ans;
    }
};
