const int MOD = 1e9 + 7;
class Solution {
public:
     vector<long long> baseUnit;
    unordered_map<int, vector<pair<int, int>>> graph;

    void dfs(int node, long long value) {
        baseUnit[node] = value % MOD;
        
        for (auto& [neighbor, factor] : graph[node]) {
            if (baseUnit[neighbor] == -1) { 
                dfs(neighbor, (value * factor) % MOD);
            }
        }
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size()+1;
        for (auto& conv : conversions) {
            int src = conv[0], tgt = conv[1], factor = conv[2];
            graph[src].push_back({tgt, factor});
        }

        baseUnit.resize(n, -1);
        
        dfs(0, 1);

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = baseUnit[i];
        }
        return result;
    }
};