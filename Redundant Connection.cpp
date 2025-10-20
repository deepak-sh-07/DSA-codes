class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findparent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findparent(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int p1 = findparent(edges[i][0]);
            int p2 = findparent(edges[i][1]);
            if(p1==p2) ans = edges[i];
            if(rank[p1]>rank[p2]){
                parent[p2] = p1;
            }else if(rank[p1]<rank[p2]){
                parent[p1] = p2;
            }else{
                parent[p2] = p1;
                rank[p1]++;
            }
        }
        return ans;
    }
};
