class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        if(i==n || j==m || i<0 || j<0 || visited[i][j]==-1 || grid[i][j]==0) return false;
        return true;
    }
    bool helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,long long &sum ,int k){
        if(!isValid(i,j,grid,visited)) return false;
        visited[i][j] = -1;
        sum = sum+grid[i][j];
        helper(i,j+1,grid,visited,sum,k); // right
        helper(i,j-1,grid,visited,sum,k); // left
        helper(i-1,j,grid,visited,sum,k); // up
        helper(i+1,j,grid,visited,sum,k); // down
        if(sum%k==0) return true;
        return false;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==-1) continue;
                long long sum = 0;
                if(helper(i,j,grid,visited,sum,k)==true) count++;
            }
        }
        return count;
    }
};
