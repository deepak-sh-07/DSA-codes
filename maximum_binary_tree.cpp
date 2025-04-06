class Solution {
    public:
        vector<int> v;
        int return_max(int lo,int hi){
            int idx = -1;
            int max = INT_MIN;
            for(int i = lo;i<=hi;i++){
                if(v[i]>max){
                    max = v[i];
                    idx = i;
                }
            }
            return idx;
        }
        TreeNode* construct(int lo,int hi){
            if(lo>hi) return NULL;
            int max = return_max(lo,hi);
            TreeNode* main = new TreeNode(v[max]);
            if(max!=lo){
                TreeNode* l = construct(lo,max-1);
                main->left = l;
            }
            if(max!=hi){
                TreeNode* r = construct(max+1,hi);
                main->right = r;
            }
            
            
            return main;
         }
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            v.clear();
            v.assign(nums.begin(),nums.end());
            return construct(0,nums.size()-1);
        }
    };//654