bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int binarySearch(vector<int>& potions, long long ans) {
        int lo = 0, hi = potions.size() - 1;
        if (ans > potions[hi]) return -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (potions[mid] >= ans)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);   // ✅ FIXED: properly sized
        sort(potions.begin(), potions.end());

        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({spells[i], i});
        }
        sort(arr.begin(), arr.end(), cmp);

        for (int i = 0; i < n; i++) {
            long long ele = (success + arr[i][0] - 1) / arr[i][0];  
            int j = binarySearch(potions, ele);
            if (j == -1) ans[arr[i][1]] = 0;
            else ans[arr[i][1]] = m - j;
        }
        return ans;
    }
};
