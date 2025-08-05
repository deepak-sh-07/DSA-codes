class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;
        int j = 0, i = 0;
        while (i < n && j < n) {
            if (baskets[j] >= fruits[i]) {
                count++;
                baskets[j] = 0;
                j++;
            } else {
                int x = j;
                while (x < n && baskets[x] < fruits[i])
                    x++;
                if (x != n) {
                    count++;
                    baskets[x] = 0;
                }
            }
            i++;
        }
        return n - count;
    }
};
