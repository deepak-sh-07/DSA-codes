class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.push_back({});
        for (int i = 0; i < n; i++) {
            int m = ans.size();
            for (int j = 0; j < m; j++) {
                vector<int> v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
