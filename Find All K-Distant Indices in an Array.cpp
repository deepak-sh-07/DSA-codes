class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> equal;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                for (int j = i - k; j <= i + k; j++) {
                    if (j >= 0 && j < n)
                        mp[j]++;
                }
        }
        vector<int> ans;
        for (auto ele : mp) {
            ans.push_back(ele.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
