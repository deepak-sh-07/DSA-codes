class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> helper(n,false);
        for(int i=0;i<edges.size();i++){
            helper[edges[i][1]]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(helper[i]==false) ans.push_back(i);
        }
        return ans;
    }
};
