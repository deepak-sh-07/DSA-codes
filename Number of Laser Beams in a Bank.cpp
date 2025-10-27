class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int laser = 0;
        int last = 0;
        for (int i = 0; i < n; i++) {
            string s = bank[i];
            int curr = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '1')
                    curr++;
            }
            if (curr != 0) {
                laser = laser + last * curr;
                last = curr;
            }
        }
        return laser;
    }
};
