class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int layers = min(m,n)/2;
        for(int layer=0;layer<layers;layer++){
            vector<int> nums;
            int top = layer;
            int bottom = n-1-layer;
            int left = layer;
            int right = m-1-layer;
            //top row
            for(int j=left;j<=right;j++){
                nums.push_back(grid[top][j]);
            }
            //right col
            for(int i=top+1;i<=bottom-1;i++){
                nums.push_back(grid[i][right]);
            }
            //bottom row
            for(int j=right;j>=left;j--){
                nums.push_back(grid[bottom][j]);
            }
            //left col
            for(int i=bottom-1;i>=top+1;i--){
                nums.push_back(grid[i][left]);
            }
            int new_k = k%nums.size();
            int idx = new_k;
            int x = 0;
            while(x<nums.size()){
                for(int j=left;j<=right;j++){
                grid[top][j] = nums[idx++];
                if(idx==nums.size()) idx = 0;
            }
            //right col
            for(int i=top+1;i<=bottom-1;i++){
                grid[i][right]= nums[idx++];
                if(idx==nums.size()) idx = 0;
            }
            //bottom row
            for(int j=right;j>=left;j--){
                grid[bottom][j]= nums[idx++];
                if(idx==nums.size()) idx = 0;
            }
            //left col
            for(int i=bottom-1;i>=top+1;i--){
                grid[i][left]= nums[idx++];
                if(idx==nums.size()) idx = 0;
            }
            x++;
            }
        }
        return grid;
    }
};
