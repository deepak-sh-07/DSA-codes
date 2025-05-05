class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int res = *max_element(nums.begin(),nums.end());
            int cmin = 1,cmax = 1;
            for(int i=0;i<nums.size();i++){
                int temp = cmax*nums[i];
                cmax = max({temp,cmin*nums[i],nums[i]});
                cmin = min({temp,cmin*nums[i],nums[i]});
                res = max(res,cmax);
            }
            return res;
        }
    };