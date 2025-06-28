class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& ans){
        if(graph[curr].size()==0){
            ans[curr] = true;
            return true;
        }
        if(visited[curr]==true) {
            if(ans[curr]==true) return true;
            else {
                ans[curr] = false;
                return false;
            }
        }
        visited[curr] = true;
        for(auto ele:graph[curr]){
            if(dfs(ele,graph,visited,ans)==false){
                ans[curr] = false;
                return false;
            }
        }
        ans[curr] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<bool> visited(n);
       vector<bool> ans(n); 
       for(int i=0;i<n;i++){
        if(visited[i]==true) continue;
        ans[i] = dfs(i,graph,visited,ans);
       }
       vector<int> result;
       for(int i=0;i<n;i++){
        if(ans[i]==true) result.push_back(i);
       }
       return result;
    }
};
