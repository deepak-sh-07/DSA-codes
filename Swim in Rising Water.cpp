class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> visited(n, vector<int>(m, -1));
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [max_d, r, c] = pq.top();
            pq.pop();
            if (visited[r][c] != -1)
                continue;
            visited[r][c] = 1;
            if (r == n - 1 && c == m - 1)
                return max_d;
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && visited[nr][nc]==-1){
                    int new_d = max(max_d, grid[nr][nc]);
                    pq.push({new_d, nr, nc});
                }
            }}
            return -1;
        }
    };
