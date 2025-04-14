class Solution {
    public:
        int findClosest(int x, int y, int z) {
            int first = abs(x-z);
            int second = abs(y-z);
            if(first<second) return 1;
            else if(second<first) return 2;
            return 0;
        }
    };