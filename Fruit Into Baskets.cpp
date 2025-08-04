class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int type_1;
        int type_2 = -1;
        int count = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            type_1 = nums[i];
            int j = i + 1;
            while (j < n) {
                if (nums[j] != type_1 && type_2 == -1) {
                    type_2 = nums[j];
                    count++;
                    maxi = max(maxi, count);
                } else if (nums[j] == type_1 || nums[j] == type_2) {
                    count++;
                    maxi = max(maxi, count);
                } else {
                    type_2 = -1;
                    count = 1;
                    break;
                }
                j++;
                if (j == n) {
                    type_2 = -1;
                    count = 1;
                }
            }
        }
        return maxi;
    }
};
