class Solution {
public:
    int UPB(const vector<vector<int>>& matrix, int target) {
        auto it = upper_bound(
            matrix.begin(),
            matrix.end(),
            target,
            [](int value, const vector<int>& row) {
                return value < row[0];
            }
        );
        return it - matrix.begin(); 
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<vector<int>> left, right;
        
        for (int i = 0; i < n; ++i) {
            if (fruits[i][0] <= startPos)
                left.push_back({startPos - fruits[i][0], fruits[i][1]});
            else
                right.push_back({fruits[i][0] - startPos, fruits[i][1]});
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        vector<int> psum_l(left.size() + 1, 0), psum_r(right.size() + 1, 0);
        for (int j = 0; j < left.size(); ++j) psum_l[j + 1] = psum_l[j] + left[j][1];
        for (int j = 0; j < right.size(); ++j) psum_r[j + 1] = psum_r[j] + right[j][1];

        int maxi = 0;

        for (int i = 0; i <= k; ++i) {
            int ub_left = UPB(left, i);
            int ub_right = UPB(right, k - 2 * i);
            maxi = max(maxi, psum_l[ub_left] + psum_r[ub_right]);

            ub_right = UPB(right, i);
            ub_left = UPB(left, k - 2 * i);
            maxi = max(maxi, psum_l[ub_left] + psum_r[ub_right]);
        }

        return maxi;
    }
};
