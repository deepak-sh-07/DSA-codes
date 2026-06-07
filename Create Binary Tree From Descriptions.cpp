/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef pair<TreeNode*,bool> pi;
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int,pi> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int root = arr[i][0];
            int child = arr[i][1];
            TreeNode* curr;
            if(mp.find(root)!=mp.end()) curr = mp[root].first;
            else{
                curr = new TreeNode(root);
                mp[root] = {curr,false};
            }
            TreeNode* ch;
            if(mp.find(child)!=mp.end()){
                ch = mp[child].first;
                mp[child].second = true;
            }
            else{
                ch = new TreeNode(child);
                mp[child] = {ch,true};
            }
            if(arr[i][2]==1) curr->left = ch;
            else curr->right = ch;
        }
        TreeNode* ans;
        for(auto ele:mp){
            if(ele.second.second==false){
                ans =  ele.second.first;
                break;
            }
        }
        return ans;
    }
};
