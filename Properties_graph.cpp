
class Solution {
    public:
        
    
        vector<list<int>> graph;
        int intersect(vector<int> a,vector<int> b){
            unordered_map<int,int> pq;
            for(int i=0;i<a.size();i++){
                pq[a[i]]++;
            }
            int total = 0;
            for(int i=0;i<b.size();i++){
                if(pq.find(b[i])!=pq.end()){
                    total++;
                    pq.erase(b[i]);
                }
            }
          return total;  
        }
        void create(int src,int dest){
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        void dfs(int node,vector<int>& visited){
            visited[node] = 0;
            for(auto neighbour:graph[node]){
                if(visited[neighbour]==-1) dfs(neighbour,visited);
            }
        }
        int numberOfComponents(vector<vector<int>>& arr, int k) {
            int n = arr.size();
            graph.clear();
            graph.resize(n);
            for(int i=0;i<n-1;i++){ //create
                for(int j=i+1;j<n;j++){
               if(intersect(arr[i],arr[j])>=k) create(i,j);
            }}
            int cc = 0;
            vector<int> visited(n,-1);
            for(int i=0;i<n;i++){
                if(visited[i]==-1) cc++;
                dfs(i,visited);
            }
            return cc;
        }
    };