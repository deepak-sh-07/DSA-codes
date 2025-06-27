class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int curr,vector<bool>& visited){
        visited[curr] = true;
        for(auto ele:rooms[curr]){
            if(!visited[ele]){
                dfs(rooms,ele,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,0,visited);
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};
