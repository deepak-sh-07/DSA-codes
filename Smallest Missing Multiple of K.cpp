class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int i;
        for (i = 1; i <= 100 / k; i++) {
            int x = i * k;
            if (mp.find(x) == mp.end())
                return x;
        }
        return i * k;
    }
};
