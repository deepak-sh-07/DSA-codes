class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> rowSum(n), colSum(m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                rowSum[i] += grid[i][j], colSum[j] += grid[i][j];

        vector<long long> prefixRow(n), suffixRow(n);
        prefixRow[0] = rowSum[0];
        for (int i = 1; i < n; ++i)
            prefixRow[i] = prefixRow[i - 1] + rowSum[i];
        suffixRow[n - 1] = rowSum[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixRow[i] = suffixRow[i + 1] + rowSum[i];

        for (int i = 0; i < n - 1; ++i) {
            if (prefixRow[i] == suffixRow[i + 1]) return true;
        }

        vector<int> prefixCol(m), suffixCol(m);
        prefixCol[0] = colSum[0];
        for (int i = 1; i < m; ++i)
            prefixCol[i] = prefixCol[i - 1] + colSum[i];
        suffixCol[m - 1] = colSum[m - 1];
        for (int i = m - 2; i >= 0; --i)
            suffixCol[i] = suffixCol[i + 1] + colSum[i];

        for (int i = 0; i < m - 1; ++i) {
            if (prefixCol[i] == suffixCol[i + 1]) return true;
        }

        return false;
    }
};
