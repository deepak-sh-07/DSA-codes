class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<char>>& grid,int a,int b,bool &ans,vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0) return;
        if(grid[i][j]!=grid[a][b]) return;
        if(visited[i][j]!=-1){
            ans = true;
            return;
        }
        visited[i][j] = 1;
        for(int x=0;x<4;x++){
            int ni = i+dir[x][0];
            int nj = j+dir[x][1];
            if(ni==a && nj==b) continue;
            dfs(ni,nj,grid,i,j,ans,visited);
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1) continue;
                bool ans = false;
                dfs(i,j,grid,i,j,ans,visited);
                if(ans==true){
                    cout<<i<<" "<<j;
                    return true;
                    
                }
            }
        } 
        return false;
    }
};
