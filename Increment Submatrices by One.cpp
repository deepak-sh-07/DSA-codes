class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][2];
            int x = queries[i][1], y = queries[i][3];
            for (int l = a; l <= b; l++) {
                for (int r = x; r <= y; r++) {
                    ans[l][r] += 1;
                }
            }
        }
        return ans;
    }
};
