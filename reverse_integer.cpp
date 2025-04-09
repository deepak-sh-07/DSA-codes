class Solution {
    public:
        int reverse(int x) {
            long m = 0;
    
            while (x != 0) {
                m = m * 10 + x % 10;
                x = x / 10;
            }
            if (m < INT_MIN || m > INT_MAX) {
                return 0;
            }
            return m;
        }
    };
    