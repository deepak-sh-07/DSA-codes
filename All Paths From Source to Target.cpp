class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<int> &ans,vector<vector<int>>& final){
        if(i==graph.size()-1){
            final.push_back(ans);
            return;
        }
        for(auto ele:graph[i]){
            ans.push_back(ele);
            dfs(ele,graph,ans,final);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> final_ans;
        vector<int> ans;
        ans.push_back(0);
        dfs(0,graph,ans,final_ans);
        return final_ans;
    }
};
