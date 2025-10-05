class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
    vector<vector<int>> h;
    vector<vector<bool>> bfs(queue<pair<int,int>> &q){
       vector<vector<bool>>visited(rows,vector<bool>(cols,false));
       while(!q.empty()){
        auto cell = q.front();
        q.pop();
        int a = cell.first;
        int b = cell.second;
        visited[a][b] = true;
        for(int d = 0;d<4;d++){
            int newr = a+dir[d][0];
            int newc = b+dir[d][1];
            if(newr<0 || newc<0 || newr>=rows || newc>=cols) continue;
            if(visited[newr][newc]) continue;
            if(h[newr][newc]<h[a][b]) continue;
            q.push({newr,newc});
        }
       }
       return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        rows = arr.size();
        cols = arr[0].size();
        h = arr;
        queue<pair<int,int>> pacificbfs;
        queue<pair<int,int>> atlanticbfs;
        for(int i=0;i<rows;i++){
            pacificbfs.push({i,0});
            atlanticbfs.push({i,cols-1});
        }
        for(int i=1;i<cols;i++){
            pacificbfs.push({0,i});
        }
        for(int i=0;i<cols-1;i++){
            atlanticbfs.push({rows-1,i});
        }
       vector<vector<bool>> pacific = bfs(pacificbfs);
       vector<vector<bool>> atlantic = bfs(atlanticbfs);
       vector<vector<int>> ans;
       for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(pacific[i][j]==true && atlantic[i][j]==true) ans.push_back({i,j});
        }
       }
       return ans;
    }
};
