class Solution {
    public:
        int dp[5005][2];
        int f(vector<int>& prices, int i, int tr) {
            int n = prices.size();
            if (i >= n)
                return 0;
            if (dp[i][tr] != -1)
                return dp[i][tr];
            int buy = INT_MIN, sell = INT_MIN, skip;
            if (tr == 0)
                buy = f(prices, i + 1, 1) - prices[i];
            if (tr == 1)
                sell = f(prices, i + 2, 0) + prices[i];
            skip = f(prices, i + 1, tr);
            return dp[i][tr] = max({buy, sell, skip});
        }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            memset(dp, -1, sizeof(dp));
            return f(prices, 0, 0);
        }
    };