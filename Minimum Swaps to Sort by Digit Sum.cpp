class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> data(n);

        for (int i = 0; i < n; ++i) {
            data[i] = {sumOfDigits(nums[i]), nums[i], i};
        }

        sort(data.begin(), data.end());

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[get<2>(data[i])] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || pos[i] == i)
                continue;

            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                swaps++;
            }
            swaps--;
        }

        return swaps;
    }
};
