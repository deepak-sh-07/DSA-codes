class Solution {
public:
    void dfs(int curr,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[curr]=true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[curr][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};
