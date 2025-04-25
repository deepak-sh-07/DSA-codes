class Solution {
    public:
        int compareVersion(string version1, string version2) {
            int n = version1.size();
            int m = version2.size();
            int c1 = 0, c2 = 0;
            for (int i = 0, j = 0; i < n || j < m; i++, j++) {
                while (i < n && version1[i] != '.') {
                    c1 = 10 * c1 + (version1[i++] - '0');
                }
                while (j < m && version2[j] != '.') {
                    c2 = 10 * c2 + (version2[j++] - '0');
                }
                if (c1 < c2)
                    return -1;
                else if (c2 < c1)
                    return 1;
                c1 = 0;
                c2 = 0;
            }
            return 0;
        }
    };