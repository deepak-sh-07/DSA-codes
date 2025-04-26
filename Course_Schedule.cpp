class Solution {
    public:
        vector<vector<int>> graph;
        vector<int> state;
        bool hascycle(int i) {
            if (state[i] == 1)
                return true; // cycle found
            if (state[i] == 2)
                return false; // processed
            state[i] = 1;
            for (int neighbour : graph[i]) {
                if (hascycle(neighbour))
                    return true;
            }
            state[i] = 2; // visited
            return false;
        }
        bool canFinish(int n, vector<vector<int>>& arr) {
            graph.resize(n);
            state.resize(n, 0);
            int m = arr.size();
            for (auto& pre : arr) {
                graph[pre[0]].push_back(pre[1]);
            }
            for (int i = 0; i < n; i++) {
                if (hascycle(i))
                    return false;
            }
            return true;
        }
    };