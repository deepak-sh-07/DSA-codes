
class Solution {
  public:
    void helper(Node *root , int val,int &maxi,unordered_map<int,vector<int>> &mp){
        if(!root) return;
        mp[val].push_back(root->data);
        maxi = max(maxi,val);
        helper(root->left,val+1,maxi,mp);
        helper(root->right,val,maxi,mp);
    }
    vector<int> diagonal(Node *root) {
        unordered_map<int,vector<int>> mp;
        int maxi = 1;
        vector<int> ans;
        helper(root,1,maxi,mp);
        for(int i=1;i<=maxi;i++){
            for(auto ele:mp[i]){
                ans.push_back(ele);
            }
        }
        
        return ans;
    }
};
