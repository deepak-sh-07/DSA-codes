class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        long long x = 1;
        for (int i = 1; i < 25; i++) {
            x *= 3;
            if (x == n)
                return true;
        }
        return false;
    }
};
