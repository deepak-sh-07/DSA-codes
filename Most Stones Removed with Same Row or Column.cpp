class Solution {
public:
    void dfs(int i, vector<vector<int>>& stones, vector<bool>& visited) {
        visited[i] = true;
        int n = stones.size();
        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])) {
                dfs(j, stones, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int count = 0;  

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, stones, visited);
                count++;
            }
        }

        return n - count;
    }
};
