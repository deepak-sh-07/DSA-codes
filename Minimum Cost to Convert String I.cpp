class Solution {
public:
    void dijkstra(int src, vector<pair<int, int>> adj[], vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            auto [d,n] = pq.top();
            pq.pop();
            if(d>dist[n]) continue;
            for(auto [nn,wt]:adj[n]){
                if(dist[nn]>d+wt){
                    dist[nn]=d+wt;
                    pq.push({dist[nn],nn});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<pair<int, int>>
            adj[26]; // VVV diff from vector<pair<int,int>> adj(26)
        for (int i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
            dijkstra(i, adj, dist[i]);
        }
        long long ans = 0;
        for(int i=0;i<source.length();i++){
            int x = source[i]-'a';
            int y = target[i]-'a';
            if(x==y) continue;
            if(dist[x][y]==INT_MAX) return -1;
            ans += dist[x][y];
        }
        return ans;
    }
};
