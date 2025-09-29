

class Solution {
  public:
 
    int size(Node *root){
        if(root==NULL) return 0;
        return 1+max(size(root->left),size(root->right));
    }
    void nth(Node *root,int curr,int level,vector<int>& v){
        if(curr>level || root==NULL) return;
        if(curr==level){
            v.push_back(root->data);
            return;
        }
        nth(root->left,curr+1,level,v);
        nth(root->right,curr+1,level,v);
    }
    void level(Node *root,vector<vector<int>> &ans){
        int height = size(root);
        for(int i=1;i<=height;i++){
            vector<int> v;
            nth(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        level(root,ans);
        return ans;
    }
};
