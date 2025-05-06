class Solution {
    public:
      vector<vector<int>> graph;
      void create(int src,int dest){
          graph[src].push_back(dest);
          graph[dest].push_back(src);
      }
      vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
          graph.resize(V);
          for(int i=0;i<edges.size();i++){
              create(edges[i].first,edges[i].second);
          }
         return graph; 
      }
  };