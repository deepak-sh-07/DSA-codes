class Solution {
public:
    vector<list<int>> graph;
    void creategraph(int src, int dest) {
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    void dfs(int i, int& count, vector<int>& vis) {
        vis[i] = true;
        count++;
        for (auto ele : graph[i]) {
            if (vis[ele] == false) {
                dfs(ele, count, vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.clear();
        graph.resize(n);
        long long ans = n / 2;
        ans *= n - 1;
        if (edges.size() == 0)
            return ans;
        for (int i = 0; i < edges.size(); i++) {
            creategraph(edges[i][0], edges[i][1]);
        }
        vector<int> vis(n, false);
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                int count = 0;
                dfs(i, count, vis);
                arr.push_back(count);
            }
        }
        long long total = 0;
        if (arr.size() == 1)
            return 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                long long prod = arr[i];
                prod *= arr[j];
                total += prod;
            }
        }
        return total;
    }
};
