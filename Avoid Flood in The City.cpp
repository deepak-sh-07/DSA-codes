class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mp;
        set<int> dry;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dry.insert(i);
                ans[i] = 1;
            } else {
                ans[i] = -1;
                if (mp.find(rains[i]) != mp.end()) {
                    auto it = dry.lower_bound(mp[rains[i]]);
                    if (it == dry.end())
                        return {};
                    ans[*it] = rains[i];
                    dry.erase(it);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};
