class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s = to_string(grid[i][j]);
                int len = s.length();
                if(ans[j]<len) ans[j] = len;
            }
        }
        return ans;
    }
};
