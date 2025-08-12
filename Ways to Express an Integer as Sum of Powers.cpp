class Solution {
public:
    const int MOD = 1000000007;
    vector<vector<int>> dp;

    int Pow(int base, int exp, int limit) {
        long long result = 1;
        for (int j = 0; j < exp; j++) {
            result *= base;
            if (result > limit) return limit + 1; 
        }
        return (int)result;
    }
    
    int f(int i, int x, int target) {
        if (target == 0) return 1;
        if (target < 0 || i>dp.size()-1) return 0;
        if (dp[i][target] != -1) return dp[i][target];

        int sub = Pow(i, x, target); 
        if (sub > target) return 0;

        long long pick = f(i + 1, x, target - sub) % MOD;
        long long not_pick = f(i + 1, x, target) % MOD;

        return dp[i][target] = (pick + not_pick) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return f(1, x, n) % MOD;
    }
};
