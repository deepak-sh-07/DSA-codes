class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int odd = 0, even = 0, odd_even = 0, even_odd = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1)
                odd++;
            else if (nums[i] % 2 == 0)
                even++;
        }
        // odd starting
        int i = 0;
        while (i < n) {
            if (nums[i] % 2 == 1) {
                odd_even++;
                i++;
            } else {
                while (i < n && nums[i] % 2 != 1)
                    i++;
                if (i == n)
                    break;
                odd_even++;
            }
            if (i == n)
                break;
            if (nums[i] % 2 == 0) {
                odd_even++;
                i++;
            } else {
                while (i < n && nums[i] % 2 != 0)
                    i++;
                if (i == n)
                    break;
                odd_even++;
            }
        }
        // even starting
        i = 0;
        while (i < n) {
            if (nums[i] % 2 == 0) {
                even_odd++;
                i++;
            } else {
                while (i < n && nums[i] % 2 != 0)
                    i++;
                if (i == n)
                    break;
                even_odd++;
            }
            if (i == n)
                break;
            if (nums[i] % 2 == 1) {
                even_odd++;
                i++;
            } else {
                while (i < n && nums[i] % 2 != 1)
                    i++;
                if (i == n)
                    break;
                even_odd++;
            }
        }
        return max({odd, even, odd_even, even_odd});
    }
};
