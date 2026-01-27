class Solution {
public:
    typedef pair<int,int> pi;
    vector<list<pi>> graph;
    void create(int src,int dest,int wt){
        graph[src].push_back({dest,wt});
        graph[dest].push_back({src,2*wt});
    }
    int dijkstra(int n){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int dis = top.first;
            int node = top.second;
            for(auto ele:graph[node]){
                if(dist[ele.first]>dis+ele.second){
                    dist[ele.first] = dis+ele.second;
                    pq.push({dis+ele.second,ele.first});
                }
            }
        }
        return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        graph.clear();
        graph.resize(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            create(edges[i][0],edges[i][1],edges[i][2]);
        }
        int ans = dijkstra(n);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
