class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<long long> powers;

        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) == 1) {
                powers.push_back(1LL << i);
            }
        }

        // Prefix product
        for (int i = 1; i < powers.size(); i++) {
            powers[i] = (powers[i] * powers[i - 1]) % MOD;
        }

        vector<int> ans(queries.size());

        auto modInverse = [&](long long a) {
            long long res = 1, exp = MOD - 2;
            while (exp) {
                if (exp & 1) res = (res * a) % MOD;
                a = (a * a) % MOD;
                exp >>= 1;
            }
            return res;
        };

        for (int i = 0; i < queries.size(); i++) {
            int first = queries[i][0];
            int second = queries[i][1];
            long long res = powers[second];
            if (first != 0) {
                res = (res * modInverse(powers[first - 1])) % MOD;
            }
            ans[i] = (int)res;
        }

        return ans;
    }
};
