class Solution {
public:
    int n;

    int f_2(vector<vector<int>>& fruits, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || i >= n || j < 0 || j >= n) return -1e9; // bounds
        if (fruits[i][j] == -1) return -1e9;
        if (j!=n-1 && fruits[i][j+1] == -1) return -1e9;
        if (i == n - 2) return fruits[i][j]; // base: last row
        
        if (dp[i][j] != -1) return dp[i][j];

        int downLeft = f_2(fruits, i + 1, j - 1, dp);
        int down     = f_2(fruits, i + 1, j, dp);
        int downRight= f_2(fruits, i + 1, j + 1, dp);

        return dp[i][j] = fruits[i][j] + max({downLeft, down, downRight});
    }

    int f_3(vector<vector<int>>& fruits, int i, int j, vector<vector<int>>& dp) {
        if (i >= n ) return -1e9; // bounds
        if (fruits[i][j] == -1) return -1e9;
        if (j>0 && fruits[i][j-1] == -1) return -1e9;
        if (j == n - 2) return fruits[i][j]; // base: last column
        if (dp[i][j] != -1) return dp[i][j];
        int upRight    = f_3(fruits, i - 1, j + 1, dp);
        int right      = f_3(fruits, i,     j + 1, dp);
        int downRight  = f_3(fruits, i + 1, j + 1, dp);

        return dp[i][j] = fruits[i][j] + max({upRight, right, downRight});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int count = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            count += fruits[i][j];
            fruits[i][j] = -1;
            i++;
            j++;
        }
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int y = f_3(fruits, n - 1, 0, dp1);   // bottom left
        int x = f_2(fruits, 0, n - 1, dp2);   // top right
        return count+x+y ;
    }
};
